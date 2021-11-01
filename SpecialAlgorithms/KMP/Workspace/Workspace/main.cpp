#include <iostream>
#include <cstring>

using namespace std;
#define MaxSize 10

void getNext(int next[], string t)
{
    int j = 0, k = -1;
    next[0] = -1;
    while (j < t.length() - 1) {
        if (k == -1 || t[j] == t[k]) {
            j++; k++;
            next[j] = k;
        }
        else k = next[k];
    }
}

int KMP(string s, string t)
{
    int next[MaxSize], i = 0, j = 0;
    getNext(next, t);
    while (i < s.length() && j < t.length()) {
        if (j == -1 || s[i] == t[j]) {
            i++; j++;
        }
        else j = next[j];
    }
    
    if (j >= t.length()) {
        return i - (int)t.length();
    }
    else return -1;
}

int main()
{
    string s = "I'm Jack.";
    string t = "I am";
    
    cout << KMP(s, t) << endl;
    return 0;
}
