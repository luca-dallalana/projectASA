#include <iostream>
#include <vector>
using namespace std;
// compile g++ -std=c++11 -O3 -Wall projeto1.c++ -lm ./a.out
int maximizeValue(int X, int Y, int n, vector<vector<int>>& pieces) { // receives the pointer to the vector
    vector<vector<int>> tabela(X + 1, vector<int>(Y + 1, 0)); // vetor de tamanho X+1 que contem vetores de tamanho Y+1
    // fills the matrix (bottom-up method)
    for (int i = 1; i <= X; i++) { // somatorio
        for (int j = 1; j <= Y; j++) { // somatorio

            tabela[i][j] = max(tabela[i-1][j], tabela[i][j-1]); // inicializa a posicao com o maior dos vetores anteriores

            for (int k = 0; k < n; k++) { // itera as pecas
                int ai = pieces[k][0];
                int bi = pieces[k][1];
                int pi = pieces[k][2];
                if (i >= ai && j >= bi) { // se as pecas tem tamanho suficiente normalmente
                // max entre valor de uma peca previa ou o valor da area sem a peca mais o valor da peca
                    tabela[i][j] = max(tabela[i][j], tabela[i - ai][j - bi] + pi); 
                }
                if (i >= bi && j >= ai) { // se as pecas tem tamanho suficiente viradas
                    tabela[i][j] = max(tabela[i][j], tabela[i - bi][j - ai] + pi);
                }
            }
        }
    }
    return tabela[X][Y]; // o resultado optimo e o resultado final da tabela
}

int main() {
    int X, Y, n;
    cin >> X >> Y; // reads the variables for height and length
    cin >> n; // reads the variable that represents the number of different pieces

    vector<vector<int>> pieces(n, vector<int>(3)); // builds a vector of vectors that contains information about all the pieces
    for (int i = 0; i < n; i++) {
        cin >> pieces[i][0] >> pieces[i][1] >> pieces[i][2]; // reads the height, length and price of every piece
    }
    int result = maximizeValue(X, Y, n, pieces); // calls the auxiliary function that calculates the best deal
    cout << result << endl; // prints to the terminal the answer

    return 0;
}