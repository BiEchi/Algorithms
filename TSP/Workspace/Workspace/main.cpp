#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define numOfVertices 4

// use adjacency matrix for graph
int TSP(int graph[][numOfVertices], int sourceVertex)
{
    vector<int> vertices;
    // store all vertices except for the source vertex
    for (int vertex = 0; vertex < numOfVertices; vertex++) {
        if (vertex != sourceVertex) {
            vertices.push_back(vertex);
        }
    }
    
    // store minimum weight Hamiltonian cycle
    int minPathWeight = INT_MAX;
    do {
        int currentPathWeight = 0;
        
        // compute current path weight
        int k = sourceVertex;
        for (int i = 0; i < vertices.size(); i++) {
            currentPathWeight += graph[k][vertices[i]];
            k=vertices[i];
            cout << vertices[i] << " ";
        }
        cout << endl;
        // go back
        currentPathWeight += graph[k][sourceVertex];
        
        // update minimum path weight
        minPathWeight = min(minPathWeight, currentPathWeight);
    }
    // complete permutation algorithm. modify memory directly.
    while (next_permutation(vertices.begin(), vertices.end()));
    
    return minPathWeight;
}

int main()
{
    int graph[][numOfVertices] ={
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int sourceVertex = 0;
    cout << TSP(graph, sourceVertex) << endl;
    return 0;
}
