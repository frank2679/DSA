#include <iostream>
#include <string>
#include "my_header.h"
using namespace std;

#define N 100
int main()
{
    struct Entry entry[N];
    buildStruct(entry);
    printEntry(entry[0]);
    // do interactive according to input
    string s; 
    while(cin >> s)
        switch(mapStringInteger(s))
        {
            case 1: 
                int u,i,t;
                cin >> u >> i >> t ;
                cout << u << ' ' << i << ' ' << t << endl;
                cout << "here is accept" << endl;
                break;

            case 2: 
                cout << "here is items" << endl;
                break;

            case 3: 
                cout << "here is users" << endl;
                break;

            case 4: 
                cout << "here is ratio" << endl;
                break;

            case 5: 
                break;
            default:
                cout << "Invalid input" << endl;
        }
    return 0;
}
