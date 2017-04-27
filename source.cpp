#include"header.h"
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<list>
#include<queue>
using namespace std;

istream& operator>>(istream& is, student& en)                 //overloading of >> operator for reading objects of class cycle from a file
{
    is >> en.RollNo;
    is >> en.Name;
    is >> en.Hostel;
    is >> en.Room;
    is >> en.Phone;
    is >> en.issueDate;
    return is;
}

ostream& operator<<(ostream& os, const student& en)           //overloading of << operator for writing objects of class cycle into a file
{
    os << en.RollNo<<" ";
    os << en.Name<<" ";
    os << en.Hostel<<" ";
    os << en.Room<<" ";
    os << en.Phone<<" ";
    os << en.issueDate<<"\n";
    return os;
}

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
    int i;
    student temp;
    for(i=0; i<en.Total-en.Available; i++)
    {
        is>>temp;
        (en.IssuedTo).push_back(temp);
    }
    if(en.Available == 0)
    {
        int t;
        is >> t;
        for(i=0; i<t; i++)
        {
            is>>temp;
            (en.Waitlist).push(temp);
        }
    }
    return is;
}

ostream& operator<<(ostream& os, const cycle& en)           //overloading of << operator for writing objects of class cycle into a file
{
    os << en.Brand<<" ";
    os << en.Model<<" ";
    os << en.MRP<<" ";
    os << en.Gear<<" ";
    os << en.Type<<" ";
    os << en.Category<<" ";
    os << en.Total<<" ";
    os << en.Available<<"\n";
    int i =0;
    for(list<student>::const_iterator it=(en.IssuedTo).begin(); it!=(en.IssuedTo).end() && i<en.Total-en.Available; it++,i++)
        os << (*it);
    if(en.Available == 0)
    {
        os << en.Waitlist.size();
        queue<student> Q = en.Waitlist;
        while(!Q.empty())
        {
            os << Q.front();
            Q.pop();
        }
    }
    return os;
}

istream& operator>>(istream& is, vector<cycle>& en)
{
    is>>systemDate;
    cycle temp;
    while (1) {
        is>>(temp);
        if (!is.eof())
            en.push_back(temp);
        else
            break;
    }
    return is;
}

ostream& operator<<(ostream& os, const vector<cycle>& en)
{
    os<<systemDate<<"\n";
    size_t n=en.size();
    for (size_t it = 0; it < n; it++)
        os<<(en.at(it));
    return os;
}

void student::getDetails()
{
    cout<<"Congratulations on selecting your cycle. Please enter the following Details:"<<endl;
    cout<<"Roll No: ";
    cin>>RollNo;
    cout<<"Name: ";
    cin>>Name;
    cout<<"Hostel No: ";
    cin>>Hostel;
    cout<<"Room No: ";
    cin>>Room;
    cout<<"Phone No: ";
    cin>>Phone;
    issueDate = systemDate;
}

void student::calculateRent(float MRP)
{
    int numDays = systemDate - issueDate + 1;
    float amt = 0;
    if (numDays <= 5)
    {
        amt = MRP * 0.1;
    }
    else if (numDays <= 15)
    {
        amt = (MRP * 0.1) + ((numDays -5) * 0.01 * MRP);
    }
    else
    {
        amt = (MRP * 0.1) + (10 * 0.01 * MRP) + ((numDays-15) * 0.005 * MRP);
    }
    cout<<"Thank You for renting with us!"<<endl;
    cout<<"Please take back your security deposit"<<endl;
    cout<<"Your Total Due Amt for "<<numDays<<" days is "<<amt<<"."<<endl;
    cout<<"Please press ENTER to complete the transaction. We hope to see you soon.";
    getchar();
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
}

// Function to Issue a cycle
bool cycle::Issue(){
    if(Available>0) {
        Available--;
        student s;
        s.getDetails();
        IssuedTo.push_back(s);
        cout<<"Please pay  "<<MRP*0.5<<" as SECURITY Deposit"<<endl;
        cout<<"Thank You. Please Hit ENTER to complete the transaction";
        getchar();
        return true;
    }
    else{
        student s;
        s.getDetails();
        Waitlist.push(s);
        return false;
        }
};

// Function to Return a cycle
bool cycle::Return()
{
    if (Available+1 > Total)
        return false;
    else
    {
        string roll_temp;
        cout<<" Please enter your Roll No: ";
        cin>> roll_temp;
        int flag = 0;
        for (list<student>::iterator it=IssuedTo.begin(); it!= IssuedTo.end(); ++it)
        {
            if((*it).returnRollNo() == roll_temp)
            {
                (*it).calculateRent(MRP);
                IssuedTo.erase(it);
                flag = 1;
                Available++;
                break;
            }
        }

        if (!flag)
        {
            cout<<"Sorry, Invalid Info!";
            return false;
        }

        if(!Waitlist.empty())
        {
        IssuedTo.push_back(Waitlist.front());
        Waitlist.pop();
        Available--;
        cout<<"Waitlisted Customer issued cycle";
        }
        return true;
    }
}

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

string cycle::getBrand() {
    return Brand;
}

string cycle::getModel() {
    return Model;
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

void Display(vector<cycle> vect) {
    vector<cycle>::iterator it;
    for ( it = vect.begin(); it < vect.end(); it++) {
        it->Display();
    }
}



