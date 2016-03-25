/* B-directional list help search ?
 * if not, just implement unordered list
 * reason: can't access element randomly.
 */
#include <iostream>
#include <string>
#include <list>
#include "my_header.h"
using namespace std;

int main()
{
    list<Entry> mylist;  // list of entry, entry is one piece of log.
    list<Entry>::iterator it;
    list<Entry> *ptr_list = &mylist;
    buildStruct(ptr_list);
    cout << "size of data is " << ptr_list->size() << endl;
    
    /********test for accept_cal()**********//*{{{*/
    //int item_ = 1760350;
    //rmDuplicate(ptr_list);
    //cout << "accept_num function of item " << item_ << " return " << accept_cal(item_, ptr_list) << endl;;
    //item_ = 1760351;
    //cout << "accept_num function of item " << item_ << " return " << accept_cal(item_, ptr_list) << endl;;
    //cout << "after remove size of data is " << ptr_list->size() << endl;
    /*}}}*/
    /********** test for ratio ********//*{{{*/
    //cout << "ratio is " << ratio(ptr_list) << endl;;/*}}}*/

    /**************************************** do interactive according to input **/ 
    int n;
    scanf("%d", &n);
    string s; 
    while(n--)
    {
        cout << "Please select the action(accept, items, users, ratio, findtime_item):" << endl;
        cin >> s;
        cin.ignore();
        ptr_list = &mylist;
        switch(mapStringInteger(s))
        {
            case 1: 
                accept(ptr_list);
                break;
            case 2: 
                items(ptr_list);
                break;
            case 3: 
                users(ptr_list);
                break;
            case 4: 
                ratio(ptr_list);
                break;
            case 5: 
                findtime_item(ptr_list);
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }

    return 0;
}
