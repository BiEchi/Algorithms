/* This is the program to simulate a DFA on an input string. Please name your
 * file "DFA.txt" or input your string from the console. The code will output
 * whether your input string is a valid regular language or not. The input file
 * should have the format below:
 *
 *  #states #alphabet (your input alphabet will be enumerated by 1, 2, ..., M)
 *  #final_states final_state_1 final state_2 ...
 *  #transitions
 *  previous_state input_symbol #next_states next_state1 next_state2 ...
 *  previous_state input_symbol #next_states next_state1 next_state2 ...
 *  previous_state input_symbol #next_states next_state1 next_state2 ...
 *  ...
 *
 * Please note that 0 is the start state, and
 *
 * Credits for https://github.com/kartikkukreja/blog-codes/blob/master/src/DFA%20simulation.cpp - all right reserved.
 */

#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <set>
#include <bitset>
#include <cstring>
#define MAX_NFA_STATES 10
#define MAX_ALPHABET_SIZE 10
using namespace std;
 
// initialize the states
class NFAstate {
    public:
        int transitions[MAX_ALPHABET_SIZE][MAX_NFA_STATES];
        NFAstate()  {
            for(int i=0; i<MAX_ALPHABET_SIZE; i++)
                for(int j=0; j<MAX_NFA_STATES; j++)
                    transitions[i][j] = -1;
        }
} *NFAstates;

set <int> NFA_finalStates;
bitset <MAX_NFA_STATES> currentStates;
char input_string[100000];
int N;
 
// finds the epsilon closure of the NFA state "state" and stores it into "closure"
void epsilonClosure(int state, bitset<MAX_NFA_STATES> &closure )    {
    for(int i=0; i<N && NFAstates[state].transitions[0][i] != -1; i++)
        if(closure[NFAstates[state].transitions[0][i]] == 0)    {
            closure[NFAstates[state].transitions[0][i]] = 1;
            epsilonClosure(NFAstates[state].transitions[0][i], closure);
        }
}
 
// finds the epsilon closure of a set of NFA states "state" and stores it into "closure"
void epsilonClosure(bitset<MAX_NFA_STATES> state, bitset<MAX_NFA_STATES> &closure) {
    for(int i=0; i<N; i++)
        if(state[i] == 1)
            epsilonClosure(i, closure);
}
 
// returns a bitset representing the set of states the NFA could be in after moving
// from state X on input symbol A
void NFAmove(int X, int A, bitset<MAX_NFA_STATES> &Y)   {
    for(int i=0; i<N && NFAstates[X].transitions[A][i] != -1; i++)
        Y[NFAstates[X].transitions[A][i]] = 1;
}
 
// returns a bitset representing the set of states the NFA could be in after moving
// from the set of states X on input symbol A
void NFAmove(bitset<MAX_NFA_STATES> X, int A, bitset<MAX_NFA_STATES> &Y)   {
    bitset<MAX_NFA_STATES> tmp;
    for(int i=0; i<N; i++)
        if(X[i] == 1)
            NFAmove(i, A, tmp);
    Y = tmp;
}

void loadNFA(int& M){
    int F, X, Y, A, T;
    ifstream fin("NFA.txt");
    fin >> N >> M;
    NFAstates = new NFAstate[N];
    fin >> F;
    for(int i=0; i<F; i++)    {
        fin >> X;
        NFA_finalStates.insert(X);
    }
    fin >> T;
    while(T--)   {
        fin >> X >> A >> Y;
        for(int i=0; i<Y; i++)  {
            int j;
            fin >> j;
            NFAstates[X].transitions[A][i] = j;
        }
    }
    fin.close();
}

bool simulateNFA(const int M){
    char* p;
    int symbol;
    
    printf("Enter a string ('.' to exit) : ");
    scanf("%[^\n]%*c", input_string);
    while(input_string[0] != '.')   {
        currentStates[0] = 1;
        epsilonClosure(currentStates, currentStates);
 
        p = strtok(input_string, " ");
        while(p)    {
            symbol = atoi(p);
            if(symbol <= 0 || symbol > M)   {
                printf("Invalid input symbol %d.\n", symbol);
                return false;
            } else {
                NFAmove(currentStates, symbol, currentStates);
                epsilonClosure(currentStates, currentStates);
            }
            p = strtok(NULL, " ");
        }
 
        int i;
        for(i = 0; i < N; i++)
            if(currentStates[i] == 1 && NFA_finalStates.find(i) != NFA_finalStates.end())
                break;
 
        if(i < N)
            printf("String accepted.\n");
        else
            printf("String rejected.\n");
 
        printf("Enter a string ('.' to exit) : ");
        scanf("%[^\n]%*c", input_string);
    }
    return true;
}
 
int main()  {
    int M;
 
    loadNFA(M);
    if (!simulateNFA(M)) return -1;
    return 0;
}
