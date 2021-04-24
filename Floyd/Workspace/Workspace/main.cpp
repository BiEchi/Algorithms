
#include <iostream>

using namespace std;

#define max_n 4;

void Floyd(int n, float& graphMatrix[][n], int& pathMatrix[][n])
{
    int i, j, v;
    int A[n][n]; // temporary matrix
    
    // initialization
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = graphMatrix[i][j];
            pathMatrix[i][j] = -1;
        }
    }
    
    // well-known 3-for iterations
    for (v = 0; v < n; v++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (A[i][j] > A[i][v] + A[v][j]) {
                    A[i][j] = A[i][v] + A[v][j];
                    pathMatrix[i][j] = v;
                }
            }
        }
    }
}

void printPathIteratively(int u, int v, int pathMatrix[][])
{
    if (pathMatrix[u][v] == -1)
        cout << pathMatrix[u][v] << endl;
    else
    {
        int mid = pathMatrix[u][v];
        printPathIteratively(u, mid, pathMatrix);
    }
}

int main()
{
    int pathMatrix[4][4] =
    printPath(1, 2, pathMatrix);
    
    return 0;
}
