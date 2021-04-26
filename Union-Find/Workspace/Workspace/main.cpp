#include <iostream>
#include <vector>

using namespace std;

class DisjointSets
{
public:
    explicit DisjointSets(int numOfElements);
    
    int find(int x);
    void unionSets(int root1, int root2);
    void add(int x);
    void display(int numOfElements);
    
private:
    int numOfElements;
    vector<int> s;
};

/// build the disjoint set object (ctor)
/// @param numOfElements initial number of disjoint sets
DisjointSets::DisjointSets(int numOfElements)
: s(numOfElements, -1)
{
    this->numOfElements = numOfElements;
}

void DisjointSets::add(int x)
{
    s.push_back(x);
    
    return;
}

void DisjointSets::display(int numOfElements)
{
    for (int i = 0; i < numOfElements; i++) {
        cout << s[i] << " ";
    }
}

/// unite two disjoint sets; assume root 1 & root 2 are not the same and represent a name of set respectively; use the rank method
/// @param root1 the root of set 1
/// @param root2 the root of set 2
void DisjointSets::unionSets(int root1, int root2)
{
    /* buggy
    if (s[root2] < s[root1]) {
        s[root1] = root2; // parentLink(root1) := root2
    } else {
        if (s[root1] == s[root2])
            --s[root1];
        s[root2] = root1; // parentLink(root2) := root1
    }
     */
    
    s[root2] = root1;
    
    return;
}

/// find the set incl. x
/// @param x the given element
/// @return the set that includes x
int DisjointSets::find(int x)
{
    if (s[x] < 0)
        return x;
    else
        return find(s[x]);
}

int main()
{
    DisjointSets DS(6);
    cout << "The set is initialized." << endl;
    DS.display(6);
    
    cout << endl << "-------------------" << endl;
    
    DS.unionSets(1, 2);
    cout << endl << "The set is united by (1, 2)." << endl;
    DS.display(6);
    
    DS.unionSets(3, 4);
    cout << endl << "The set is united by (3, 4)." << endl;
    DS.display(6);
    
    cout << endl << "Is 1 and 4 in the same equivalent class now?" << endl;
    cout << (DS.find(1) == DS.find(4)) << endl;
    
    DS.unionSets(2, 3);
    cout << endl << "The set is united by (2, 3)." << endl;
    DS.display(6);
    
    cout << endl << "Is 1 and 4 in the same equivalent class now?" << endl;
    cout << (DS.find(1) == DS.find(4)) << endl;
    
    return 0;
}
