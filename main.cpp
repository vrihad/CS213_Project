#include"header.h"
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;
int systemDate;

vector<cycle> Cycles;
vector<cycle*> searchList;
Trie searchTrie;

struct by_MRP {
    bool operator()(cycle* const &a, cycle* const &b) const {
        return a->MRP < b->MRP;
    }
};

cycle* Search() {
    vector<cycle*> select;
    string word;
    int choice;
    int i;
    size_t t;

    goto searching;

    choose:
    i=1;
    if(select.empty())
        cout<<"0"<<endl;
    else
    {
        for(vector<cycle*>::iterator it=select.begin(); it<select.end(); ++it,++i)
        {
            cout<<i<<endl;
            (*it)->Display();
        }
    }
    cout<<"What do you want to do?"<<endl;
    cout<<"1. Search again"<<endl;
    cout<<"2. Apply Filter"<<endl;
    cout<<"3. Select"<<endl;
    cin>>choice;
    if(choice==1)
        goto searching;
    else if(choice==2)
        goto filtering;
    else if(choice==3)
        goto selecting;
    else {
        cout<<"Invalid choice !"<<endl;
        goto choose;
    }

    searching:
    cout<<"Enter Brand or Model of the cycle: ";
    cin>>word;
    searchTrie.Find(word,select);
    goto choose;

    filtering:
    cout<<"Please choose a filter from below:"<<endl;
    cout<<"1. Price (Low to High)"<<endl;
    cout<<"2. Geared"<<"\t3. Non-Geared"<<endl;
    cout<<"4. Male"<<"\t5. Female"<<"\t6. Kids"<<endl;
    cout<<"7. Road Bicycle"<<"\t8. Racing Bicycle"<<"\t9. Mountain Bike"<<"\t10. BMX"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1: sort(select.begin(), select.end(), by_MRP());
                break;
        case 2: for(vector<cycle*>::iterator it=select.begin(); it<select.end(); ++it)
                    if((*it)->Gear == false)
                        select.erase(it);
                break;
        case 3: for(vector<cycle*>::iterator it=select.begin(); it<select.end(); ++it)
                    if((*it)->Gear)
                        select.erase(it);
                break;
        case 4: for(vector<cycle*>::iterator it=select.begin(); it<select.end(); ++it)
                    if((*it)->Category == 1)
                        select.erase(it);
                break;
        case 5: for(vector<cycle*>::iterator it=select.begin(); it<select.end(); ++it)
                    if((*it)->Category == 2)
                        select.erase(it);
                break;
        case 6: for(vector<cycle*>::iterator it=select.begin(); it<select.end(); ++it)
                    if((*it)->Category == 3)
                        select.erase(it);
                break;
        case 7: for(vector<cycle*>::iterator it=select.begin(); it<select.end(); ++it)
                    if((*it)->Type == 1)
                        select.erase(it);
                break;
        case 8: for(vector<cycle*>::iterator it=select.begin(); it<select.end(); ++it)
                    if((*it)->Type == 2)
                        select.erase(it);
                break;
        case 9: for(vector<cycle*>::iterator it=select.begin(); it<select.end(); ++it)
                    if((*it)->Type == 3)
                        select.erase(it);
                break;
        case 10: for(vector<cycle*>::iterator it=select.begin(); it<select.end(); ++it)
                    if((*it)->Type == 4)
                        select.erase(it);
                break;
    }
    goto choose;

    selecting:
    cout<<"Enter the no. of cycle you want to select: ";
    cin>>t;
    if (t>=0 && t<select.size())
        return select.at(t-1);
    else
        return NULL;
}

int main()
{

    fstream file;
    file.open("Database.txt",ios::in);
    file>>Cycles;
    file.close();

    searchTrie.Populate(Cycles);

/*    searchTrie.Find("Avon",searchList);
    vector<cycle*>::iterator it;
    for (it=searchList.begin(); it<searchList.end(); it++)
        (*it)->Display();
*/
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
        string temp;
        cycle* tempCycle;
        cin>>choice;
        switch (choice)
        {
            case 1: Cycles.push_back(Create());
                    break;
            case 2: cout<<"Please enter the Model of the cycle you wish to Edit? ";
                    cin>>temp;
                    searchList.clear();
                    searchTrie.Find(temp,searchList);
                    if(!searchList.empty())
                        (searchList.front())->Edit();
                    else
                        cout<<"Cycle not found !!!";
                    break;
            case 3: cout<<"Please enter the Model of the cycle you wish to Delete? ";
                    cin>>temp;
                    searchList.clear();
                    searchTrie.Find(temp,searchList);
                    if(!searchList.empty())
                        for (vector<cycle>::iterator it = Cycles.begin(); it<Cycles.end(); it++)
                            if(it->Model == (searchList.front())->Model)
                                //Cycles.erase(it);
                    break;
            case 4: tempCycle=Search();
                    if(tempCycle != NULL)
                        tempCycle->Issue();
                    else
                        cout<<"You didn't choose any cycle!"<<endl;
                    break;
            case 5: cout<<"Please enter the Model of the cycle you wish to Return? ";
                    cin>>temp;
                    searchList.clear();
                    searchTrie.Find(temp,searchList);
                    if(!searchList.empty())
                        (searchList.front())->Return();
                    break;
            case 6: systemDate++;
                    file.open("Database.txt",ios::out);
                    file<<Cycles;
                    file.close();
                    goto TheEnd;
                    break;

        }
    }
    TheEnd:
    return 0;
}
