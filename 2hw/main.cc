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
    /******************************************** for testing the data loading **/
    //for(; it != mylist.end(); it++)
    //{
       // printEntry(*--it); // print the last element
    //}

    /**************************************** do interactive according to input **/ 
    string s; 
    while(1)
    {
        cout << "Please select the action(accept, items, users, ratio, findtime_item):" << endl;
        cin >> s;
        ptr_list = &mylist;
        switch(mapStringInteger(s))
        {
            case 1: 
                int u,i,t;
                cout << "please type in userID, itemID, time " << endl;
                accept(ptr_list);
                break;

            case 2: 
                cout << "please type two userID both of whom are given the same item" << endl;
                items(ptr_list);
                break;

            case 3: 
                cout << "please type in two itemIDs and an interval given by two time" << endl;
                break;

            case 4: 
                cout << "please type in an itemID and a threshold" << endl;
                break;

            case 5: 
                cout << "please type in an itemID and a user group" << endl;
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }

    return 0;
}
