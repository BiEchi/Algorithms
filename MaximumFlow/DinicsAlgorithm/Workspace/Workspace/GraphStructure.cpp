//
//  GraphStructure.cpp
//  Workspace
//
//  Created by Jack's Macbook Pro on 2021/5/11.
//

#include "GraphStructure.hpp"
#include <list>
#include <queue>
using namespace std;

/// 1. Conduct BFS to find whether there can be more flow from s to t
/// 2. Assign levels to nodes.
bool ResidualGraph::BFS(int s, int t)
{
    for (int i = 0; i < numberOfVertex; i++)
        levelOfNode[i] = -1; // initialize all vertices with level -1
    levelOfNode[s] = 0; // source vertex has level 0
    
    // levelOfNode[] array works as visited array
    queue<int> q;
    q.push(s);
    vector<Edge>::iterator i;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (i = adjacencyList[u].begin(); i != adjacencyList[u].end(); i++) {
            Edge &e = *i;
            if (levelOfNode[e.destinationVertex] < 0 && e.flow < e.capacity) {
                // level of current vertex = level of parent + 1
                levelOfNode[e.destinationVertex] = levelOfNode[u] + 1;
                q.push(e.destinationVertex);
            }
        }
    }
    // if no augmenting path left, return false
    return levelOfNode[t] < 0 ? false : true;
}

/// DFS-based function to send a flow (if BFS has returned true, showing that there is a possible
///   flow, and has constructed levels). One BFS( ) call results in multiple sendflow( ) calls, see code
///   in DinicsAlgorithm( )
/// @param flow current flow sent by parent function call
/// @param start array used to keep track of next edge to be explored. start[i] stores count of edges explored from i.
int ResidualGraph::sendFlow(int u, int flow, int t, int start[])
{
    // already reached the sink
    if (u == t)
        return flow;
    
    for ( ; start[u] < adjacencyList[u].size(); start[u]++) {
        // pick next edge from adjacency list of u
        Edge &e = adjacencyList[u][start[u]];
        
        if (levelOfNode[e.destinationVertex] == levelOfNode[u] + 1 && e.flow < e.capacity) {
            // find minimum flow from u to t
            int currentFlow = min(flow, e.capacity - e.flow);
            int temporaryFlow = sendFlow(e.destinationVertex, currentFlow, t, start); // DFS-based recursion
            if (temporaryFlow > 0) {
                e.flow += temporaryFlow;
                adjacencyList[e.destinationVertex][e.indexOfReverseEdgeInAdjacencyList].flow -= temporaryFlow;
                return temporaryFlow;
            }
        }
    }
    return 0;
}

int ResidualGraph::DinicsAlgorithm(int s, int t)
{
    if (s == t)
        return -1;
    int totalFlow = 0;
    
    while (BFS(s, t)) {
        // store how many edges are visited from 0 to numberOfVertex
        int* start = new int[numberOfVertex+1] {0};
        // while flow is not zero from s to t
        while (int flow = sendFlow(s, INT_MAX, t, start))
            totalFlow += flow;
    }
    return totalFlow;
}
