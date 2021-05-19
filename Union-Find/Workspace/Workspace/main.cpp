// A union-find algorithm to detect cycle in a graph
// In this version, we use parent[], not root[]
#include <iostream>
using namespace std;

// a structure to represent an edge in graph
class Edge
{
public:
    int src, dest;
};

// a structure to represent a graph
class Graph
{
public:
    // V-> Number of vertices, E-> Number of edges
    int numOfVertices, numOfEdges;

    // graph is represented as an array of edges
    // combinational representation
    Edge* edge;
};

// Creates a graph with V vertices and E edges
Graph* createGraph(int numOfVertices, int numOfEdges)
{
    Graph* graph = new Graph();
    graph->numOfVertices = numOfVertices;
    graph->numOfEdges = numOfEdges;

    graph->edge = new Edge[graph->numOfEdges * sizeof(Edge)];

    return graph;
}

// A utility function to find the subset of an element i
int find(int* parent, int i)
{
    // return the root
    if (parent[i] == -1)
        return i;
    // recursively return the parent
    return find(parent, parent[i]);
}

// A utility function to do union of two subsets
void Union(int* parent, int x, int y)
{
    parent[x] = y;
}

// The main function to check whether a given graph contains
// cycle or not
int isCycle(Graph* graph)
{
    // Allocate memory for creating V subsets
    int* parent = new int[graph->numOfVertices * sizeof(int)];

    // Initialize all subsets as single element sets
    memset(parent, -1, sizeof(int) * graph->numOfVertices);

    // Iterate through all edges of graph, find subset of
    // both vertices of every edge, if both subsets are
    // same, then there is cycle in graph.
    for (int i = 0; i < graph->numOfEdges; ++i) {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);

        // cycle detected
        if (x == y)
            return 1;

        // the edge connects two not-yet-unioned vertices
        Union(parent, x, y);
    }
    return 0;
}

void test1()
{
    /* Let us create the following graph
        0
        |\
        | \
        1--2
     */
    int V = 3, E = 3;
    Graph* graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;

    if (isCycle(graph))
        cout << "graph contains cycle";
    else
        cout << "graph doesn't contain cycle";
    
    cout << endl;
}

void test2()
{
    /* Let us create the following graph
        0
        |
        |
        1--2--3
     */
    int V = 4, E = 3;
    Graph* graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    // add edge 0-2
    graph->edge[2].src = 2;
    graph->edge[2].dest = 3;

    if (isCycle(graph))
        cout << "graph contains cycle";
    else
        cout << "graph doesn't contain cycle";
    
    cout << endl;
}

// Driver code
int main()
{
    cout << "test 1." << endl;
    test1();
    cout << "test 2." << endl;
    test2();

    return 0;
}

// This code is contributed by rathbhupendra
