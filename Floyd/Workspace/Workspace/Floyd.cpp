#include <iostream>
#include <cstring>

using namespace std;

#define vertexNumber 5
#define INF 9999999
#define SUCCESS 0
#define FAILURE -1

/// Print the result distance matrix.
void printSolution(int dist[][vertexNumber])
{
    cout << "The result distance matrix is as below." << endl;
    for (int i = 0; i < vertexNumber; i++) {
        for (int j = 0; j < vertexNumber; j++) {
            if (dist[i][j] == INF)
                cout << "INF" << "      ";
            else
                cout << dist[i][j] << "      ";
        }
        cout << endl;
    }
}

bool kIsOnTheShortestPathFromiToj(int i, int j, int k, int dist[][vertexNumber])
{
    bool iTojThroughkIsShorter = dist[i][j] > dist[i][k] + dist[k][j];
    bool kHasAPathToj = dist[k][j] != INF;
    bool iHasAPathTok = dist[i][k] != INF;
    return iTojThroughkIsShorter && kHasAPathToj && iHasAPathTok;
}

/// The classical Floyd-Warshall Algorithm
void FloydAlgorithm(int graph[][vertexNumber])
{
    // initialize the result distance matrix to the same as the starter graph
    int dist[vertexNumber][vertexNumber];
    for (int i = 0; i < vertexNumber; i++) {
        for (int j = 0; j < vertexNumber; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    
    // main programme: for-for-for!!!
    for (int k = 0; k < vertexNumber; k++) { // intermediate vertex
        for (int i = 0; i < vertexNumber; i++) { // source vertex
            for (int j = 0; j < vertexNumber; j++) { // destination vertex
                if (kIsOnTheShortestPathFromiToj(i, j, k, dist)) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    // print the solution
    printSolution(dist);
}

int main()
{
    int graph[vertexNumber][vertexNumber] = { { 0,   3,   8,   INF,  -4  },
                                              { INF, 0,   INF, 1,    7   },
                                              { INF, 4,   0,   INF,  INF },
                                              { 2,   INF, -5,  0,    INF },
                                              { INF, INF, INF, 6,    0   } };
    FloydAlgorithm(graph);
    return SUCCESS;
}
