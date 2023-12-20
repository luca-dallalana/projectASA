#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <list>
using namespace std;

// g++ -std=c++11 -O3 -Wall projeto2.cpp -lm ./a.out

vector<int> DFST(vector<vector<int>>& adjacencyListTransposta, list<int>& visited, int people){ // DFS para o grafo transposto com ligeiras alteracoes face a DFS original
    vector<int> valueAtVertice(people+1,0); // vetor que grava o valor maximo que pode se atingir ao chegar num dito vertice
    // Algoritmo regular DFS
    vector<string> colors(people +1, "White");
    list<int> visit;
    int currentV;
    for (int v : visited){ // percorre todos os vertices pela ordem do tempo de fim dada pela 1 DFS
        if (colors[v] == "White"){
            vector<int> SCCs;
            int max = 0;
            visit.push_front(v); // adiciona a lista dos a procurar
            while (!visit.empty()){
                currentV = visit.front();
                colors[currentV] = "Gray";
                for (int adjacentV : adjacencyListTransposta[currentV]){
                    if (adjacentV != 0){ // Se houver v adjacente
                        if (colors[adjacentV] == "White"){ // Se ainda nao foi visitado
                            colors[adjacentV] = "Gray"; // Passa a ser visitado mas nao fechado ainda maybe redundante
                            visit.push_front(adjacentV);
                            break; // Para nao procurar pelos outros adjacentes, enquanto nao acaba o "ramo da arvore"
                        }
                        if (colors[adjacentV] == "Black"){ // Verifica se o vertice ja esta fechado
                            if (valueAtVertice[currentV] < valueAtVertice[adjacentV] + 1){ // Verifica se o caminho ate o vertice atual e menor do que a um adjacente +1
                                valueAtVertice[currentV] = valueAtVertice[adjacentV] + 1;
                                if (max < valueAtVertice[currentV]){ // no caso de ser um SCC com mais de um vertice, precisamos de saber o maior valor, pois todos os vertices partilharam esse valor
                                    max = valueAtVertice[currentV];
                                } 
                            }
                        }
                    }
                    else{
                        SCCs.push_back(currentV); // adiciona 
                        visit.pop_front();
                        break;
                    }
                }
            }
            for (int SCC : SCCs){
                valueAtVertice[SCC] = max; // atualiza todos os vertices de um SCC
                colors[SCC] = "Black";
            }
        }
    } 
    return valueAtVertice;
}

list<int> DFS(vector<vector<int>>& adjacencyList, int people){
    vector<string> colors(people +1, "White");
    list<int> visit;
    list<int> visited;
    int currentV;
    for (int v = 1; v <= people; v++){ // percorre todos os vertices
        if (colors[v] == "White"){
            visit.push_front(v); // adiciona a lista dos a procurar
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
    return visited;
}

int jumps(vector<int>& possiblePaths){
    int max = 0;
    for(int v : possiblePaths){
        if (v > max){
            max = v;
        }
    }
    return max;
}

int main(){
    int people, relationships;
    scanf("%d %d", &people, &relationships); 
    vector<vector<int>> adjacencyList(people + 1);
    vector<vector<int>> adjacencyListTransposta(people + 1);
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
    
    list<int> visited = DFS(adjacencyList, people);
    vector<int> possiblePaths = DFST(adjacencyListTransposta, visited, people);
    int maxPath = jumps(possiblePaths);
    printf("%d\n", maxPath);
    return 0;
}