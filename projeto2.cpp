#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

// g++ -std=c++11 -O3 -Wall projeto2.cpp -lm ./a.out

int main(){
    int people, relationships;
    scanf("%d %d", &people, &relationships); 

    if (pow(people,2) > people + relationships ){
        vector<vector<int>> adjacencyList(people + 1);

        for (int i = 0; i < relationships; i++){
            int person1, person2;
            scanf("%i %i", &person1, &person2);
            adjacencyList[person1].push_back(person2);
        }
    }
    else{
        int adjacencyMatrix[people + 1][people + 1] = {0}; 

        for (int i = 0; i < relationships; i++) {
            int person1, person2;
            scanf("%d %d", &person1, &person2);
            adjacencyMatrix[person1][person2] = 1;
        }
    }
    return 0;
    
}