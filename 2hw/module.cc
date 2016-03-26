#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include "my_header.h"
using namespace std;

// help functions
void printEntry(Entry &entry) // print will cost much time
{/*{{{*/
    cout << entry.user << ' ';
    cout << entry.item << ' ';
    cout << entry.result << ' ';
    cout << entry.time << ' ';
    cout << endl;
}   /*}}}*/

int mapStringInteger(string s)
{/*{{{*/
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
}/*}}}*/

void displayList(list<Entry> *ptr_list)// display list of entry
{/*{{{*/
    cout << "The list is " << endl;
    for(list<Entry>::iterator it = ptr_list->begin();
            it != ptr_list->end(); it++)
    {
        cout << it->user << " " << it->item << " " << it->result << " " << it->time << endl;
    }
}/*}}}*/

void buildStruct(list<Entry> *ptr_list)
{/*{{{*/
    Entry entry;
    ifstream input;
    //input.open("/tmp2/KDDCUP2012/track1/rec_log_train.txt");
    input.open("data");
    int a[4] = {0};
    // input data & build data structure
    for (; input >> a[0];) 
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
}/*}}}*/

void rmDuplicate(list<Entry> *ptr_list)
{/*{{{*/
    // data is ordered in time, we should divide the data into small group and remove duplicate. 
    // 有个小陷阱, will cause segmetation fault. 
    // use the feature of the data to remove duplicate, duplicate can only happen continuously.
    list<Entry>::iterator it1, it2, begin_it, current_it, last_it;
    begin_it = ptr_list->begin();
    current_it = begin_it;
    current_it++;
    for(; current_it != ptr_list->end(); current_it++)
    {
        last_it = current_it; last_it--;
        if(last_it->time != current_it->time)
        {
            // remove the duplicate
            for(it1 = begin_it; it1 != current_it; it1++)
            {
                it2 = it1; it2++;
                for(; it2 != current_it; it2++)
                {
                    if(it1->user == it2->user && 
                            it1->item == it2->item &&
                            it1->result == it2->result) 
                    {
                        ptr_list->erase(it2);
                        it2--;  // trap here, after erase, it2 remain, but the following move ahead. it2 should stay.  
                    }
                }
            }
            begin_it = current_it; 
        }
    }
    return;
}/*}}}*/

int accept_cal(int i, list<Entry> *ptr_list)
{/*{{{*/
    int accept_num;
    list<Entry>::iterator it;
    list<int> tmp_list; // store userID who are given item i.
    for(it = ptr_list->begin(); it != ptr_list->end(); it++)
    {
        if(it->item == i && it->result == 1)
            tmp_list.push_back(it->user);
    }
    // sort then unique to remove duplicate
    tmp_list.sort();
    tmp_list.unique();
    accept_num = tmp_list.size();
    return accept_num;
}/*}}}*/

bool searchOrderedList(int member, list<int> *ptr_list) // brute force search
{/*{{{*/
    for(list<int>::iterator it = ptr_list->begin(); it != ptr_list->end(); it++)
    {
        if(member == *it)
            return true;
    }
    return false;
}/*}}}*/

// Actions
int accept(list<Entry> *ptr_list)
{/*{{{*/
    // descrition
    //    cout << "---------------Description---------------" << endl;
    //   cout << "This action will display whether the recommendation is accepted." << endl;
    int u, i, t; 
    //  cout << "please type in userID, itemID, time " << endl;
    // cout << "u, i, t" << endl;
    cin >> u >> i >> t;
    list<Entry>::iterator it;
    it = ptr_list->begin();
    for(; it != ptr_list->end(); it++)
        if(u == it->user && i == it->item && t == it->time)
        {
            //        cout << "result of user " << u << " given item " << i << " at time " << t << " is " ;
            cout << it->result << endl;
            return 0;
        }
    //  cout << "Invalid query" << endl;
    return 1;
}/*}}}*/

void items(list<Entry> *ptr_list)
{/*{{{*/
    /************** description ***************/
    //cout << "---------------Description---------------" << endl;
    //cout << "This action will display the items which are given to both u1 and u2 " << endl;
    int u1, u2, count = 0, flag = 0;
    //cout << "please type two userID" << endl;
    //cout << "u1, u2" << endl;
    cin >> u1 >> u2;
    list<Entry> u1_list, u2_list;
    list<Entry>::iterator it;
    /***********search and store entry of user1 and user2 ************/
    it = ptr_list->begin();
    for(; it != ptr_list->end(); it++)
    {/*{{{*/
        if(it->user == u1)
            u1_list.push_back(*it);
        if(it->user == u2)
            u2_list.push_back(*it);
    }/*}}}*/

    /************** find the items ***************/
    list<int> item_list; // store the items given to u1 and u2
    for(it = u1_list.begin(); it != u1_list.end(); it++)
        for(list<Entry>::iterator it2 = u2_list.begin(); it2 != u2_list.end(); it2++)
            if(it->item == it2->item)
                item_list.push_back(it->item);
    item_list.sort();
    item_list.unique(); // remove duplicate
    /************** display the items ***************/
    //cout << "The items given to both user1 and user2 are " << endl;
    for(list<int>::iterator it_item = item_list.begin(); it_item != item_list.end(); it_item++)
    {
        cout << *it_item << endl;
        count++;
    }
    if(item_list.empty())
        cout << "no such items" << endl;
    //cout << "total_num number of users given both item1 and item2 is " << count << endl;
    return ;            
}/*}}}*/

void users(list<Entry> *ptr_list)
{/*{{{*/
    /************** description ***************/
    //cout << "---------------Description---------------" << endl;
    //cout << "This action shows the users how are given both i1 and i2 between t1 and t2" << endl;
    int i1, i2, t1, t2, count = 0, flag = 0;
    //cout << "please type in two itemIDs and two time slots" << endl;
    //cout << "i1, i2, t1, t2" << endl;
    cin >> i1 >> i2 >> t1 >> t2;
    list<int> user_list;
    /*********** search and store entry of item1 and item2 ***************/
    list<Entry> i1_list, i2_list; // i1_list store the entry with item of i1
    for(list<Entry>::iterator it1 = ptr_list->begin(); it1 != ptr_list->end(); it1++)
    {/*{{{*/
        if(it1->item == i1)
            i1_list.push_back(*it1);
        if(it1->item == i2)
            i2_list.push_back(*it1);
    }/*}}}*/


    /************** find the users between t1 and t2 ***************/
    list<Entry>::iterator it1, it2; 
    it1 = i1_list.begin();
    for(; it1 != i1_list.end(); it1++)
        if(it1->time < t1 || it1->time > t2)
        {
            i1_list.erase(it1);
            it1--;
        }
    it1 = i2_list.begin();
    for(; it1 != i2_list.end(); it1++)
        if(it1->time < t1 || it1->time > t2)
        {
            i1_list.erase(it1);
            it1--;
        }
    /************** find the users given i1 and i2 ***************/
    for(it1 = i1_list.begin(); it1 != i1_list.end(); it1++)
        for(it2 = i2_list.begin(); it2 != i2_list.end(); it2++)/*{{{*/
            if(it1->user == it2->user) // users satisfy the requirement
                user_list.push_back(it1->user);/*}}}*/
    user_list.sort();
    user_list.unique(); // remove duplicate, duplicate occur continuouly
    /************** display the users ***************/
    //cout << "The users given both item1 and item2 between t1 and t2" << endl;
    for(list<int>::iterator it_user = user_list.begin(); it_user != user_list.end(); it_user++)
    {
        cout << *it_user << endl;
        count++;
    }
    //cout << "total_num number of users given both item1 and item2 is " << count << endl;
    return ;
}/*}}}*/

double ratio(list<Entry> *ptr_list)
{/*{{{*/
    /************** description ***************/
    //cout << "---------------Description---------------" << endl;
    // cout << "This action output the ratio of #accept/#total_num" << endl;/*{{{*/
    //cout << "#total_num is the # of users who are given more than threshold times" << endl;
    //cout << "#accept is the # of users who accept the item i" << endl;
    //cout << endl << "please type in an itemID and a threshold" << endl;
    //cout << "itemID, threshold" << endl;
    int i, threshold;
    cin >> i >> threshold;/*}}}*/

    /************** calculate the total_num ***************/
    int total_num = 0;
    map<int, int> user_map;
    list<Entry>::iterator it1 = ptr_list->begin();
    // 1. build map , cost 0.5s too heavy
    int size = 0;
    for(; it1 != ptr_list->end(); it1++)
    {
        if(size < it1->user)
            size = it1->user;
    }
    vector<int> user_vec(size, 0);
    it1 = ptr_list->begin();
    for( int i; it1 != ptr_list->end(); it1++)
    {
        i = it1->user;
        user_vec[i]++ ;
    }
    // 2. find count > threshold and build a list of such users, cost 0.6s too heavy
    list<Entry> targetUser_list;
    it1 = ptr_list->begin();
    for(; it1 != ptr_list->end(); it1++)
    {
        if(user_vec[it1->user] > threshold)
        {
            targetUser_list.push_back(*it1); // this list should be used
        }
    }
    // 3. calculate total_num 
    for(vector<int>::iterator it = user_vec.begin(); it != user_vec.end(); it++)
        if(*it > threshold)
            total_num++;

    /************ calculate the accept *****************/
    int accept_num; 
    accept_num = accept_cal(i, &targetUser_list);
    cout << "accept_num is " << accept_num << endl;
    cout << "total_num is " << total_num << endl;

    /************ calculate the ratio *****************/
    double ratio;
    if(total_num != 0)
    {
        ratio = double(accept_num)/double(total_num);
        cout << ratio << endl;
        return ratio;
    }
    else
    {
        cout << 0;
        return 0;
    }
}/*}}}*/

void findtime_item(std::list<Entry> *ptr_list) // Users implemented in different ways.
{    /************** description ***************//*{{{*/
    //cout << "---------------Description---------------" << endl;
    //cout << "This action shows the time when item i was given to the user group" << endl;
    //cout << "please type in an itemID " << endl;
    int i, userID; 
    list<int> user_group;
    cin >> i; 
    //cout << "please type in userID to user group, type \"#\" to terminate " << endl;
    while(1)
    {
        cin >> userID;
        if(!cin)
        {
            cin.clear();
            break;
        }
        user_group.push_back(userID);
    }

    user_group.sort(); // help search the group

    // body
    list<Entry>::iterator it;
    for(it = ptr_list->begin(); it != ptr_list->end(); it++)
    {
        if(it->item == i)
            if(searchOrderedList(it->user, &user_group))
                cout << it->time << endl;
    }
    return;
}/*}}}*/

