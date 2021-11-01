/* This is the program to simulate a DFA on an input string. Please name your
 * file "DFA.txt" or input your string from the console. The code will output
 * whether your input string is a valid regular language or not. The input file
 * should have the format below:
 *
 *  #states #alphabet (your input alphabet will be enumerated by 1, 2, ..., M)
 *  #final_states final_state_1 final state_2 ...
 *  previous_state input_symbol next_state
 *  previous_state input_symbol next_state
 *  previous_state input_symbol next_state
 *  ...
 *
 * Please note that 0 is the start state, and
 *
 * Credits for https://github.com/kartikkukreja/blog-codes/blob/master/src/DFA%20simulation.cpp - all right reserved.
 */


#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#define MAX_DFA_STATES 10
#define MAX_ALPHABET_SIZE 10
using namespace std;

// pre-define all the storage (to be maximum)
int transitions[MAX_DFA_STATES][MAX_ALPHABET_SIZE];
bool finalStates[MAX_DFA_STATES];
char input_string[100000];

// load the DFA into the program
void loadDFA(int& N, int& M){
    int X, Y, A, F;
    ifstream fin("./DFA.txt");
    
    // use fin to assign N, M and F, with default split symbol " "
    fin >> N >> M >> F;
    // use F and fin to assign all the final states
    for(int i=0; i<F; i++)  {
        fin >> X;
        finalStates[X] = true;
    }
    // initialize all the possible transitions
    memset(transitions, -1, MAX_DFA_STATES * MAX_ALPHABET_SIZE * sizeof(int));
    // assign the true transitions
    while(!fin.eof())   {
        fin >> X >> A >> Y;
        transitions[X][A] = Y;
    }
    
    fin.close();
    return;
}

// check if the DFA is well defined
bool checkDFA(const int N, const int M){
    for(int i=0; i<N; i++){
        for(int j=1; j<=M; j++){
            // 1. some transitions are not assigned
            // 2. some transitions are more than the largest number
            if(transitions[i][j] < 0 || transitions[i][j] >= N) {
                printf("DFA not defined properly.\n");
                return false;
            }
        }
    }
    return true;
}

// simulate the DFA
bool simulateDFA(const int M){
    int state, symbol;
    char* p;
    printf("Enter a string ('.' to exit) : ");
    scanf("%[^\n]%*c", input_string);
    
    while(input_string[0] != '.')   {
        state = 0;
        // split the input string by " ", strtok means 'string token'
        p = strtok(input_string, " ");
        while(p){
            // change the symbol input into an integer (start from 1)
            symbol = atoi(p);
            printf("p=%p state=%d symbol=%d\n", p, state, symbol);
            // handle the invalid input cases
            if(symbol <= 0 || symbol > M){
                printf("Invalid input symbol %d.\n", symbol);
                return false;
            // if the input is valid,
            } else {
                // use the input symbol and map to jump from the current state to next state
                state = transitions[state][symbol];
            }
            p = strtok(NULL, " ");
        }
        
        // if the reached state is in the final state, then accept; otherwise reject
        if(finalStates[state])
            printf("ACCEPTED\n");
        else
            printf("REJECTED\n");

        printf("Enter a string ('.' to exit) : ");
        scanf("%[^\n]%*c", input_string);
    }
    return true;
}

int main(){
    
    int N, M;

    loadDFA(N, M);
    if (!checkDFA(N, M)) return -1;
    if (!simulateDFA(M)) return -1;
    
    return 0;
}
