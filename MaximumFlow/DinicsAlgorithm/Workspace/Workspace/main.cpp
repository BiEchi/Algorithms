// implementation for BFS Dinic

#include <iostream>
#include <vector>
#include "GraphStructure.hpp"
using namespace std;

int main()
{
    // still the same statistics with the Ford Fulkerson's Example
    ResidualGraph g(6);
    g.addEdge(0, 1, 16);
    g.addEdge(0, 2, 13);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 12);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 4, 14);
    g.addEdge(3, 2, 9);
    g.addEdge(3, 5, 20);
    g.addEdge(4, 3, 7);
    g.addEdge(4, 5, 4);
    
    cout << "Maximum Flow is " << g.DinicsAlgorithm(0, 5) << endl;
    
    return EXIT_SUCCESS;
}
