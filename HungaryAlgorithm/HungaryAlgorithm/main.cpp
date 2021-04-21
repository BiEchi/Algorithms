//
//  main.cpp
//  HungaryAlgorithm
//
//  Created by Jack's Macbook Pro on 2021/4/21.
//

#include <iostream>
using namespace std;

// The Hungary Algorithm is used to find the perfect match in a bipartite graph in p-time.

#define numOfElementsInLeftSet 4
#define numOfElementsInRightSet 4

int Map[numOfElementsInLeftSet][numOfElementsInRightSet]
    = {1, 1, 1, 1,/**/ 0, 1, 0, 0,/**/ 1, 0, 0, 0,/**/ 0, 0, 0, 0};
int p[numOfElementsInRightSet];
bool visit[numOfElementsInRightSet];

bool match(int i)
{
    for (int j = 0; j < numOfElementsInLeftSet; j++) {
        if (Map[i][j] != 0 && visit[j] == 0) {
            visit[j] = true;
            if (p[j] == 0 || match(p[j])) { // match(p[j]) means the initially matched left element can find a new match (not this one)
                // RECURSION YES!!!
                p[j] = i;
                return true;
            }
        }
    }
    return false;
}

int Hungarian()
{
    int count = 0;
    for (int i = 0; i < numOfElementsInLeftSet; i++) {
        memset(visit, 0, sizeof(visit));
        if (match(i)) {
            count++;
        }
    }
    return count; // number of successfull matches
}

int main(int argc, const char * argv[]) {
    cout << Hungarian() << endl;
    
    return 0;
}
