#include <iostream>
#include <vector>
using namespace std;
// compile g++ -std=c++11 -O3 -Wall projeto1.c++ -lm ./a.out
int maximizeValue(int X, int Y, int n, vector<vector<int>>& pieces) { // receives the pointer to the vector
    vector<vector<int>> tabela(X + 1, vector<int>(Y + 1, 0)); // vetor de tamanho X+1 que contem vetores de tamanho Y+1
    // fills the matrix (bottom-up method)
    for (int length = 1; length <= X; length++) { // somatorio
        for (int height = 1; height <= Y; height++) { // somatorio

            tabela[length][height] = max(tabela[length-1][height], tabela[length][height-1]); // inicializa a posicao com o maior dos vetores anteriores

            for (int k = 0; k < n; k++) { // itera as pecas
                int ai = pieces[k][0]; // X
                int bi = pieces[k][1]; // Y
                int pi = pieces[k][2]; // P
                if (length >= ai && height >= bi) { // se as pecas tem tamanho suficiente normalmente
                // max entre valor de uma peca previa ou o valor da area sem a peca mais o valor da peca
                    tabela[length][height] = max(tabela[length][height], max(tabela[length][height - bi] + pi + tabela[length - ai][bi],tabela[length-ai][height] + pi + tabela[ai][height - bi])); 
                }   
                if (length >= bi && height >= ai) { // se as pecas tem tamanho suficiente viradas
                    tabela[length][height] = max(tabela[length][height], max(tabela[length][height - ai] + pi + tabela[length - bi][ai],tabela[length-bi][height] + pi + tabela[bi][height - ai]));
                }
            }
    
        }
      
    }
    return tabela[X][Y]; // o resultado optimo e o resultado final da tabela
}

int main() {
    int X, Y, n;
    cin >> X >> Y; // reads the variables for length and height
    cin >> n; // reads the variable that represents the number of different pieces

    vector<vector<int>> pieces(n, vector<int>(3)); // builds a vector of vectors that contains information about all the pieces
    for (int i = 0; i < n; i++) {
        cin >> pieces[i][0] >> pieces[i][1] >> pieces[i][2]; // reads the length, height and price of every piece
    }
    int result = maximizeValue(X, Y, n, pieces); // calls the auxiliary function that calculates the best deal
    cout << result << endl; // prints to the terminal the answer

    return 0;
}