#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
// compile g++ -std=c++11 -O3 -Wall projeto1.cpp -lm ./a.out

int maximizeValue(int X, int Y, vector<vector<int>> pieceValues) { // receives the pointer to the vector
    vector<vector<int>> tabela(X + 1, vector<int>(Y + 1, 0)); // vetor de tamanho X+1 que contem vetores de tamanho Y+1
    // fills the matrix (bottom-up method)  
    for (int length = 1; length <= X; length++) { // somatorio
        for (int height = 1; height <= Y; height++) { // somatorio
            
            tabela[length][height] = pieceValues[length][height]; // inicializa a posicao com o maior dos vetores anteriores
            
            for (int lengthPiece = 1; lengthPiece < length; lengthPiece++){ 
                tabela[length][height] = max(tabela[length][height], tabela[length - lengthPiece][height] + tabela[lengthPiece][height]);
            }
            for (int heightPiece = 1; heightPiece < height; heightPiece++){
                tabela[length][height] = max(tabela[length][height], tabela[length][height - heightPiece] + tabela[length][heightPiece]);
            }
        }
    }
    return tabela[X][Y]; // o resultado optimo e o resultado final da tabela
}

int main() {
    int X, Y, n;
    scanf("%d %d", &X, &Y); // reads the variables for length and height
    scanf("%d", &n); // reads the variable that represents the number of different pieces
    if(X < 1 || Y < 1 || n < 1){
        return 0;
    }
    int pieceLength, pieceHeight, piecePrice;
    vector<vector<int>> pieceValues(X+1, vector<int>(Y+1, 0));
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &pieceLength, &pieceHeight, &piecePrice); // reads the length, height and price of every piece
        if (pieceLength <= X && pieceHeight <= Y){
            pieceValues[pieceLength][pieceHeight] = piecePrice;
        }
        if (pieceHeight <= X && pieceLength <= Y ){
            pieceValues[pieceHeight][pieceLength] = piecePrice;
        }
    }
    int result = maximizeValue(X, Y,pieceValues ); // calls the auxiliary function that calculates the best deal
    printf("%d\n", result); // prints to the terminal the answer

    return 0;
}