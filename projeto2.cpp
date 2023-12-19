#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

// g++ -std=c++11 -O3 -Wall projeto2.cpp -lm ./a.out

int DFS(vector<vector<int>>& adjacencyList, int personSearched, int people){
}

int main(){
    int people, relationships;
    scanf("%d %d", &people, &relationships); 
    vector<vector<int>> adjacencyList(people + 1);
    vector<vector<int>> adjacencyListTransposta(people + 1);
    int jumps = 0;
    for (int i = 0; i < relationships; i++){ // cria a lista de adjacencia do grafo normal e do grafo transposto (grafo transposto serve pra decobrir SCCs)
        int person1, person2;
        scanf("%i %i", &person1, &person2);
        adjacencyList[person1].push_back(person2);
        adjacencyListTransposta[person2].push_back(person1);
    }
    for (int i = 0; i < people + 1; i++){ // no final de cada adjacencyList adiconar um 0, util para os SCCs
        adjacencyList[i].push_back(0);
        adjacencyListTransposta[i].push_back(0);
    }
    

    return 0;
}