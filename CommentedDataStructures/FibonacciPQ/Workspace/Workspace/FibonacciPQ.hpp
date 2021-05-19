#ifndef _FibonacciPQ_H
#define _FibonacciPQ_H
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class FibonacciPQ
{
    // API functions
public:
    FibonacciPQ()
    {
        PQ_length = 0;
        BucketLength = 10;
        Minptr = NULL;
        Rootlist = list<Person *>();
        Degreebucket = vector<Person *>(10, NULL);
        storePeople = vector<Person>();
        Rootsize = 0;
    }
    int returnLength();
    bool isEmpty();
    bool inSert(int key);
    bool eatPeople(vector<int> people);
    int popMin();
    int find(string ID, list<int> &findingList);
    vector<int> returnStorePeople();
    list<int> getRootlist();

private:
    // method space
    void removeNode(int handle);
    Person *link(Person *a_prt, Person *b_ptr);
    Person *decreaseKey(Person *changeStatusPerson, string &profession_status, string &riskStatus_status);
    void rebalance();
    void addSonPerson(Person *sonPerson, Person *parentPerson);
    void cut(Person *sonPerson, Person *parentPerson);
    void newPerson(Person *newroot);
    bool cascadingCut(Person *parent);
    Person *stand_in(Person *copy_person_ptr);
    bool freeSon(Person *parent_node);

    // member variables space
    int PQ_length;
    int BucketLength;
    size_t Rootsize;
    Person *Minptr; // ptr pointing to the smallest root
    list<int> Rootlist;
    vector<Person *> Degreebucket;
    vector<Person> storePeople;
};

#endif
