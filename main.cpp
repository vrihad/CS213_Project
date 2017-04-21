#include"header.h"
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    vector<vector<cycle> > database;
    vector<cycle> brand;
    cycle temp,kemp;
    temp.Brand = "Hercules";
    temp.Model = "Dynamite";
    temp.Type = 2;
    temp.Category = 1;
    temp.Gear = false;
    temp.MRP = 6000;
    temp.Total = 10;
    temp.Available = 10;
    brand.push_back(temp);
    temp.Brand = "Avon";
    temp.Model = "Landmine";
    temp.Type = 1;
    temp.Category = 2;
    temp.Gear = true;
    temp.MRP = 6500;
    temp.Total = 10;
    temp.Available = 10;
    brand.push_back(temp);
    database.push_back(brand);

    fstream file;
    file.open("Database.txt",ios::out);
    file<<brand;
    file.close();

    brand.clear();

    file.open("Database.txt",ios::in);
    file>>brand;
    file.close();

    Display(brand);
    return 0;
}
