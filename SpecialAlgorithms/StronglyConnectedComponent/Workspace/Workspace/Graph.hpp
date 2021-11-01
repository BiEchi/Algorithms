//
//  Graph.hpp
//  Workspace
//
//  Created by Jack's Macbook Pro on 2021/5/1.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <iostream>
#include <list>
#include <stack>

using namespace std;

/// origin definition of the Graph
class Graph
{
private:
    int vertexNumber;
    list<int>* arrayOfAdjacencyLists;
    
    void fillOrder(int vertexID, bool visited[], stack<int>& Stack);
    void DFSUtil(int vertexID, bool visited[]);
    
public:
    Graph(int vertexNuumber);
    void addEdge(int vertex1ID, int vertex2ID);
    void printSCCs();
    Graph getTranspose();
};

#endif /* Graph_hpp */
