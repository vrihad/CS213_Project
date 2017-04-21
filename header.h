#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class student {
    string RollNo;
    string Name;
    unsigned short int Hostel;
    unsigned short int Room;
    string Phone;
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
    friend void Display(vector<cycle>);
    friend cycle Create();
    friend cycle* Search(vector<vector<cycle> >);
};

istream& operator>>(istream& is, cycle& en);
ostream& operator<<(ostream& os, const cycle& en);
istream& operator>>(istream& is, vector<cycle>& vect);
ostream& operator<<(ostream& os, const vector<cycle>& vect);

#endif // HEADER_H_INCLUDED
