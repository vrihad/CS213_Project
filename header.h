#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<stdio.h>

using namespace std;

#define ALPHABET_SIZE 26
extern int systemDate;

int code(char ch);

class student {
    string RollNo;
    string Name;
    unsigned short int Hostel;
    unsigned short int Room;
    string Phone;
    int issueDate;
  public:
    void getDetails();
    void calculateRent(float MRP);
    string returnRollNo() {return RollNo;};
};

class cycle {
  public:
    string Brand;
    string Model;
    float MRP;
    bool Gear;      //true for gear and false for non gear
    int Type;
    int Category;
    int Total;
    int Available;
    list<student> IssuedTo;
    queue<student> Waitlist;
    void Edit();
    bool Issue();
    bool Return();
    void Display();
    string getBrand();
    string getModel();
    friend cycle Create();
    friend cycle* Search();
    friend struct by_MRP;
};

cycle Create();
void Display(vector<cycle>);
cycle* Search();

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
    list<cycle*> List;
};

class Trie {
    TrieNode* root;
  public:
    Trie() {
        root = new TrieNode;
        root->isLeaf = false;
        for(int i=0; i<ALPHABET_SIZE; i++)
            (root->children)[i] = NULL;
    };
    void Add(cycle&);
    bool Remove(string);
    void Populate(vector<cycle>&);
    void Find(string,vector<cycle*>&);
};

istream& operator>>(istream& is, cycle& en);
ostream& operator<<(ostream& os, const cycle& en);
istream& operator>>(istream& is, vector<cycle>& vect);
ostream& operator<<(ostream& os, const vector<cycle>& vect);


#endif // HEADER_H_INCLUDED
