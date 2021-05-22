#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define numberOfVertex 10

/// conduct the Breadth First Search on the residual graph
/// @param residualGraph the residual graph
/// @param sourceVertex ID of source vertex
/// @param sinkVertex ID of sink vertex
/// @param parent the parent vertex array
/// @return true if find an augmenting path from source to sink, false if don't
bool BFS(int residualGraph[numberOfVertex][numberOfVertex], int sourceVertex, int sinkVertex, int parent[] /* int* parent also valid */ )
{
    // initially no vertices is visited
    bool visited[numberOfVertex];
    memset(visited, 0, sizeof(visited));
    
    // sourceVertex is enqueued, visited, and has no parent
    queue<int> q;
    q.push(sourceVertex);
    visited[sourceVertex] = true;
    parent[sourceVertex] = -1;
    
    // standard BFS approach
    while (!q.empty()) {
        // take the first vertex in the queue as the starter vertex
        int uVertex = q.front();
        q.pop();
        
        // iterate to find the ending vertex
        for (int vVertex = 0; vVertex < numberOfVertex; vVertex++) {
            // take all unvisited adjacency vertices in the residual graph
            if (visited[vVertex] == false && residualGraph[uVertex][vVertex] > 0) {
                // reach the sink vertex, no need to execute BFS any more
                if (vVertex == sinkVertex) {
                    parent[vVertex] = uVertex;
                    return true;
                }
                
                // not yet reach the sink vertex, continue BFS
                q.push(vVertex);
                parent[vVertex] = uVertex;
                visited[vVertex] = true;
            }
        }
    }
    
    // cannot reach sinkVertex
    return false;
}

/// conduct Ford Fulkerson Algorithm on the given graph
/// @param sourceVertex ID of the source vertex
/// @param sinkVertex ID of the sink vertex
int fordFulkerson(int graph[numberOfVertex][numberOfVertex], int sourceVertex, int sinkVertex)
{
    int uVertex, vVertex;
    
    // set the residual graph to be the same as initial graph
    int residualGraph[numberOfVertex][numberOfVertex];
    for (uVertex = 0; uVertex < numberOfVertex; uVertex++) {
        for (vVertex = 0; vVertex < numberOfVertex; vVertex++) {
            residualGraph[uVertex][vVertex] = graph[uVertex][vVertex];
        }
    }
    
    // store path and flow
    int parent[numberOfVertex];
    int maxFlow = 0;
    
    // if we can find an augmenting path from source to sink
    while (BFS(residualGraph, sourceVertex, sinkVertex, parent)) {
        // find minimum residual capacity of the path developed by BFS
        int pathFlow = INT_MAX;
        for (vVertex = sinkVertex; vVertex != sourceVertex; vVertex = parent[vVertex]) {
            uVertex = parent[vVertex];
            pathFlow = min(pathFlow, residualGraph[uVertex][vVertex]);
        }
        
        // update the residual graph
        for (vVertex = sinkVertex; vVertex != sourceVertex; vVertex = parent[vVertex]) {
            uVertex = parent[vVertex];
            residualGraph[uVertex][vVertex] -= pathFlow;
            residualGraph[vVertex][uVertex] += pathFlow;
        }
        
        maxFlow += pathFlow;
    }
    
    return maxFlow;
}

int main()
{
    // adjacency matrix of the given graph
    /// Note. if 0, then no edge, because algorithm will never go through a flow of 0
    int graph[numberOfVertex][numberOfVertex]
    = { { 0, 2, 3, 4, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 3, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 3, 2, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 1, 0, 8, 0, 0 }, // d
        { 0, 0, 0, 0, 0, 0, 0, 0, 2, 4 },
        { 0, 0, 0, 0, 0, 5, 0, 0, 2, 4 }, // f
        { 0, 0, 0, 0, 0, 3, 0, 0, 0, 7 }, // g
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 }, // h
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // t
    };
    
    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5) << endl;
    
    return 0;
}
