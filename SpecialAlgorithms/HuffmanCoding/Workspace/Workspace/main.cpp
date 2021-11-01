#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

/// one node of the min heap
struct MinHeapNode
{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
    
    MinHeapNode(char data, unsigned freq) // ctor
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

/// function object technique
struct compare
{
    bool operator()(MinHeapNode* left, MinHeapNode* right)
    {
        return (left->freq > right->freq);
    }
};

/// recursively print all the codes
/// @param root the root of the min heap
/// @param str the data you want to output
void printCodes(struct MinHeapNode* root, string str)
{
    if (!root)
        return;
    
    if (root->data != '$')
        cout << root->data << ": " << str << endl;
    
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");

    return;
}

/// main function of Haffman Coding Process
/// @param data the data you want store in the min heap
/// @param freq the frequency to the corresponding data
/// @param size total number of data you want to code
void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;
    
    // declare the heap with priority function defined by compare()
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    // initialize the heap by dumping all the nodes into the heap
    for (int i = 0; i < size; i++)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    
    // pop and record nodes one by one
    while (minHeap.size() != 1) {
        // get the first priority node
        left = minHeap.top();
        minHeap.pop();
        // get the second priority node
        right = minHeap.top();
        minHeap.pop();
        
        // create a new node with data char '$', freq sum of two freqs
        //  and left/right node to be the first/second priority node
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        
        // add this new node into the heap
        minHeap.push(top);
    }
    
    // recursively print all nodes in the min heap
    printCodes(minHeap.top(), "");
    
    return;
}

/// main programme
int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    
    // get the number of elements in the array
    int size = sizeof(arr) / sizeof (arr[0]);
    // execute the main function
    HuffmanCodes(arr, freq, size);
    
    return 0;
}
