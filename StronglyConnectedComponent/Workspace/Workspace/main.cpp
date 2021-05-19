// We use Kosaraju's Algorithms to print all Strongly Connected Components

#include "Graph.hpp"

using namespace std;

/// the main function for printing the Strongly Connected Components
void Graph::printSCCs()
{
    stack<int> Stack;
    
    // initialize the vertices as not visited
    bool* visited = new bool[vertexNumber];
    for (int i = 0; i < vertexNumber; i++)
        visited[i] = false;
    
    // fill the stack by adding vertices according to their finishing times
    for (int i = 0; i < vertexNumber; i++)
        if (visited[i] == false)
            fillOrder(i, visited, Stack);
    
    // get the transpose of the original graph
    Graph transposedGraph = getTranspose();
    // re-initialize the array indicating whether visited
    for (int i = 0; i < vertexNumber; i++)
        visited[i] = false;
    // extract vertices from the stack
    while (!Stack.empty()) {
        int vertexID = Stack.top();
        Stack.pop();
        // perform DFS on the unvisited vertices recursively
        if (!visited[vertexID]) {
            transposedGraph.DFSUtil(vertexID, visited);
            cout << endl;
        }
    }
    
    return;
}

/// the main programme
int main()
{
    // note that this is a Digraph
    Graph g(11);
    
    // we leave out vertexID = 0 to track the example shown in exam
    // totally 15 edges
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 7);
    g.addEdge(3, 7);
    g.addEdge(1, 4);
    g.addEdge(4, 1);
    g.addEdge(4, 5);
    g.addEdge(4, 8);
    g.addEdge(5, 6);
    g.addEdge(5, 10);
    g.addEdge(8, 6);
    g.addEdge(8, 9);
    g.addEdge(9, 8);
    g.addEdge(10, 4);

    g.printSCCs();
    
    return 0;
}
