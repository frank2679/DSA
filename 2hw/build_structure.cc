#include <iostream>
#include <fstream>
#include "my_header.h"
using namespace std;
#define N 100 // N entries at a time
void buildStruct(struct Entry* entry)
{
    ifstream input;
    input.open("data");
    int a[4] = {0};
    // input data & build data structure
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < 4; j++) // j 
        {
            input >> a[j];
        }
        (entry+i)->user = a[0];
        (entry+i)->item = a[1];
        (entry+i)->result = a[2];
        (entry+i)->time = a[3];
    }
    input.close();
    return ;
}
// call by reference needn't work with parameter of reference
void printEntry(struct Entry &entry) // print will cost much time
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
