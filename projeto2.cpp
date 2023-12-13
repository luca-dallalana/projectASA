#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

// g++ -std=c++11 -O3 -Wall projeto2.cpp -lm ./a.out

int DFS(vector<vector<int>>& adjacencyList, int personSearched, int people){
    int jumps = 0;
    vector<bool> visited(people + 1, false);   
    stack<int> stack;

    visited[personSearched] = true;
    stack.push(personSearched);
    
    while (!stack.empty()){
        int currentPerson = stack.top();
        stack.pop();
        for (int knownPerson : adjacencyList[currentPerson]){
            if (!visited[knownPerson]){
                visited[knownPerson] = true;
                stack.push(knownPerson);
                jumps++;
            }
        }
    }
    return jumps - 1;
}

int main(){
    int people, relationships;
    scanf("%d %d", &people, &relationships); 
    vector<vector<int>> adjacencyList(people + 1);
    int jumps = 0;
    for (int i = 0; i < relationships; i++){
        int person1, person2;
        scanf("%i %i", &person1, &person2);
        adjacencyList[person1].push_back(person2);
    }
    for (int v = 0; v < people; v++){
        jumps = max(jumps, DFS(adjacencyList, v, people));
    }
        
    return 0;
}