#include"header.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

istream& operator>>(istream& is, cycle& en)                 //overloading of >> operator for reading objects of class cycle from a file
{
    is >> en.Brand;
    is >> en.Model;
    is >> en.MRP;
    is >> en.Gear;
    is >> en.Type;
    is >> en.Category;
    is >> en.Total;
    is >> en.Available;
    return is;
}

ostream& operator<<(ostream& os, const cycle& en)           //overloading of << operator for writing objects of class cycle into a file
{
    os << en.Brand<<"\t";
    os << en.Model<<"\t";
    os << en.MRP<<"\t";
    os << en.Gear<<"\t";
    os << en.Type<<"\t";
    os << en.Category<<"\t";
    os << en.Total<<"\t";
    os << en.Available<<"\n";
    return os;
}

istream& operator>>(istream& is, vector<cycle>& en)
{
    int n;
    is>>n;
    cycle temp;
    for (int i = 0; i < n; i++) {
        is>>(temp);
        en.push_back(temp);
    }
    return is;
}

ostream& operator<<(ostream& os, const vector<cycle>& en)
{
    os<<en.size()<<"\n";
    size_t n=en.size();
    for (size_t it = 0; it < n; it++)
        os<<(en.at(it));
    return os;
}

// function to edit parameters of a cycle object
void cycle::Edit() {
    reedit:
    cout<<"What do you want to edit?"<<endl
    <<"1 - MRP"<<endl
    <<"2 - Total"<<endl;
    int choice;
    cin>>choice;
    switch(choice) {
        case 1:
            cout<<"\nEnter new MRP: ";
            cin>>MRP;
            break;
        case 2:
            int temp;
            cout<<"\nEnter new Total: ";
            cin>>temp;
            if (temp<Total-Available)
                cout<<"\nERROR: No. of cycles issued are more than the new Total!";
            else {
                Available += temp - Total;
                Total = temp;
            }
            break;
        default:
            cout<<"\nChoice entered in not valid please enter '1' or '2' only!";
            goto reedit;
    }
};

bool cycle::Issue(){
    if(Available>0) {
        Available--;
        return true;
    }
    else
        return false;
};

bool cycle::Return() {
    if (Available+1 > Total) {
        return false;
    }
    else {
        Available++;
        return true;
    }
};

// Function to display a cycle object on console
void cycle::Display() {
    cout<<"\nBrand: "<<Brand;
    cout<<"\nModel: "<<Model;
    cout<<"\nMRP: "<<MRP;
    cout<<"\nGear: "<<(Gear?"Geared":"Non-Geared");
    cout<<"\nType: ";
    switch(Type) {
        case 1:
            cout<<"Road Bicycle";
            break;
        case 2:
            cout<<"Racing Bicycle";
            break;
        case 3:
            cout<<"Mountain Bike";
            break;
        case 4:
            cout<<"BMX";
            break;
    }
    cout<<"\nCategory: ";
    switch(Category) {
        case 1:
            cout<<"Male";
            break;
        case 2:
            cout<<"Female";
            break;
        case 3:
            cout<<"Kids";
            break;
    }
    cout<<"\nAvailability: "<<((Available>0)?"Available":"Not Available");
    cout<<endl;
}

void Display(vector<cycle> vect) {
    vector<cycle>::iterator it;
    for ( it = vect.begin(); it < vect.end(); it++) {
        it->Display();
    }
}

cycle Create() {
    cycle temp;
    cout<<"Creating a new Entry"<<endl;
    cout<<"\nEnter Brand Name: ";
    cin>>temp.Brand;
    cout<<"\nEnter Model Name: ";
    cin>>temp.Model;
    cout<<"\nEnter MRP of the cycle: ";
    cin>>temp.MRP;
    cout<<"\nEnter Gear(1)/NonGear(0): ";
    cin>>temp.Gear;                                                 //check the validity of input
    cout<<"\nEnter type of cycle as follows:"<<endl
    <<"1 - Road Bicycle"<<endl
    <<"2 - Racing Bicycle"<<endl
    <<"3 - Mountain Bike"<<endl
    <<"4 - BMX"<<endl;
    cin>>temp.Type;                                                 //check the validity of input
    cout<<"\nEnter the Category as follows:"<<endl
    <<"1 - Male"<<endl
    <<"2 - Female"<<endl
    <<"3 - Kids"<<endl;
    cin>>temp.Category;                                             //check the validity of input
    cout<<"\nEnter the total no. of cycles: ";
    cin>>temp.Total;
    temp.Available = temp.Total;
    return temp;
};
