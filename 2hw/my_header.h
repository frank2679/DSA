#include <string>
#include <list>
using namespace std;
// structure
#ifndef _ENTRY
#define _ENTRY
struct Entry
{
    int   user;
    int   item;
    int   result;
    int   time;
};
typedef struct Entry Entry;
#endif
// function
void buildStruct(list<Entry> *);
void printEntry(Entry &entry); // print will cost much time
int mapStringInteger(string s);
void rmDuplicate(list<Entry> *ptr_list);
int accept_cal(int i, list<Entry> *ptr_list);
void displayList(list<Entry> *ptr_list);
bool searchOrderedList(int, list<int> *);

// Actions
int accept(list<Entry> *);
void items(list<Entry> *);
void users(list<Entry> *);
double ratio(list<Entry> *);
void findtime_item(std::list<Entry> *); // Users implemented in different ways.

