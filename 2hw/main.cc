/* B-directional list help search ?
 * if not, just implement unordered list
 * reason: can't access element randomly.
 */
#include <iostream>
#include <string>
#include <list>
#include "my_header.h"
using namespace std;

#define N 10
int main()
{
    list<Entry> mylist;  // list of entry, entry is one piece of log.
    list<Entry>::iterator it;
    list<Entry> *ptr_list = &mylist;
    buildStruct(ptr_list);

    it = mylist.end(); // return a pointer to one plus last element
    //for(; it != mylist.end(); it++)
    //{
        printEntry(*--it); // print the last element
    //}
    // do interactive according to input
    /*
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
        */
    return 0;
}
