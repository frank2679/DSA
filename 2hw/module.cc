#include <iostream>
#include <fstream>
#include <list>
#include "my_header.h"
using namespace std;
#define N 10 // N entries at a time

// call by reference needn't work with parameter of reference
void printEntry(Entry &entry) // print will cost much time
{
    cout << entry.user << ' ';
    cout << entry.item << ' ';
    cout << entry.result << ' ';
    cout << entry.time << ' ';
    cout << endl;
}   

int mapStringInteger(string s)
{
    if (s == "accept")
        return 1;
    else if (s == "items")
        return 2;
    else if (s == "users")
        return 3;
    else if (s == "ratio")
        return 4;
    else if (s == "findtime_item")
        return 5;
}

void buildStruct(list<Entry> *ptr_list)
{
    Entry entry;
    ifstream input;
    input.open("data");
    int a[4] = {0};
    // input data & build data structure
    for (int i = 0; input >> a[0]; i++)
    {
        for(int j = 1; j < 4; j++) // j 
            input >> a[j];
        entry.user   = a[0];
        entry.item   = a[1];
        entry.result = a[2];
        entry.time   = a[3];
        ptr_list->push_back(entry);
    }
    input.close();
    return ;
}

int accept(list<Entry> *ptr_list)
{
    int u, i, t; 
    cin >> u >> i >> t;
    list<Entry>::iterator it;
    it = ptr_list->begin();
    for(; it != ptr_list->end(); it++)
        if(u == it->user && i == it->item && t == it->time)
        {
            cout << "result of user " << u << " given item " << i << " at time " << t << " is " ;
            cout << it->result << endl;
            return 0;
        }
    cout << "Invalid query" << endl;
    return 1;
}

int items(list<Entry> *ptr_list)
{
    int u1, u2;
    cin >> u1 >> u2;
    cout << "here" << endl;
}
