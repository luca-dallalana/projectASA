#include <iostream>
#include <vector>
using namespace std;

int maximizeValue(int X, int Y, int n, vector<vector<int>>& pieces) { // receives the pointer to the vector
    vector<vector<int>> dp(X + 1, vector<int>(Y + 1, 0)); // creates a new vector
    // fills the matrix (bottom-up method)
    for (int i = 1; i <= X; ++i) { // somatorio
        for (int j = 1; j <= Y; ++j) { // somatorio
            for (int k = 0; k < n; ++k) { // itera as pecas
                int ai = pieces[k][0];
                int bi = pieces[k][1];
                int pi = pieces[k][2];
                if (i >= ai && j >= bi) {
                    dp[i][j] = max(dp[i][j], dp[i - ai][j - bi] + pi);
                }
            }
        }
    }
    return dp[X][Y]; // o resultado optimo e o resultado final da tabela
}

int main() {
    int X, Y, n;
    cin >> X >> Y; // reads the variables for height and length
    cin >> n; // reads the variable that represents the number of different pieces

    vector<vector<int>> pieces(n, vector<int>(3)); // builds a vector of vectors that contains information about all the pieces
    for (int i = 0; i < n; ++i) {
        cin >> pieces[i][0] >> pieces[i][1] >> pieces[i][2]; // reads the height, length and price of every piece
    }
    int result = maximizeValue(X, Y, n, pieces); // calls the auxiliary function that calculates the best deal
    cout << result << endl; // prints to the terminal the answer

    return 0;
}