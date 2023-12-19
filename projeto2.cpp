#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <list>
using namespace std;

// g++ -std=c++11 -O3 -Wall projeto2.cpp -lm ./a.out

list<int> DFS(vector<vector<int>>& adjacencyList, int people){
    vector<string> colors(people +1, "White");
    list<int> visit;
    list<int> visited;
    int currentV;
    for (int i = 1; i <= people; i++){ // percorre todos os vertices
        if (colors[i] == "White"){
            visit.push_front(i); // adiciona a lista dos a procurar
            while (!visit.empty()){
                currentV = visit.front();
                colors[currentV] = "Gray"; // maybe redundante
                for (int adjacentV : adjacencyList[currentV]){
                    if (adjacentV != 0){ // Se houver v adjacente
                        if (colors[adjacentV] == "White"){ // Se ainda nao foi visitado
                            colors[adjacentV] = "Gray"; // Passa a ser visitado mas nao fechado ainda maybe redundante
                            visit.push_front(adjacentV);
                            break; // Para nao procurar pelos outros adjacentes, enquanto nao acaba o "ramo da arvore"
                        }
                        
                    }
                    else{ // Se nao houver adjacente
                        visited.push_front(currentV); // Adiciona o vertice a lista dos visitados
                        visit.pop_front(); // Remove o vertice da lista dos a visitar
                        colors[currentV] = "Black"; // Marca o vertice como fechado
                        break;
                    }
                    
                }
                
                
            }
            
        }
        
    }
    
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