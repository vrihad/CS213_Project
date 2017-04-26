#include"header.h"
#include<iostream>
#include<fstream>

using namespace std;
int systemDate = 0;

int main()
{
    vector<cycle> Cycles;
    vector<cycle*> searchList;

    fstream file;
    file.open("Database.txt",ios::in);
    file>>Cycles;
    file.close();

//    Display(Cycles);
    Trie searchTrie;
    searchTrie.Populate(Cycles);

    searchTrie.Find("Avon",searchList);
    vector<cycle*>::iterator it;
    for (it=searchList.begin(); it<searchList.end(); it++)
        (*it)->Display();

    int choice;
    while(1)
    {
        cout<<"WELCOME TO IITB CYCLE RENTING PORTAL"<<endl;
        cout<<"What would you like to do:"<<endl;
        cout<<"1. Add a cycle \n";
        cout<<"2. Edit a cycle \n";
        cout<<"3. Remove a cycle \n";
        cout<<"4. Rent a cycle \n";
        cout<<"5. Return a cycle \n";
        cout<<"6. Exit \n";
        cin>>choice;
        case (choice):
        {
            case 1:  cycle temp = Create();
                     Cycles.push_back(temp);
                    break;
            case 2: //inert command for searching through trie
                    break;
            case 3: //inert command for searching through trie
                    break;
            case 4:
                    break;
            case 5:
                    break;
            case 6: systemDate++;
                    file.open("Database.txt",ios::out);
                    file<<Cycles;
                    file.close();
                    exit(0);
                    break;

        }
    }

    return 0;
}
