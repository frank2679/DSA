#include <string>
#include <list>
// structure
#ifndef _ENTRY
#define _ENTRY
struct Entry
{
    int   user;
    int   item;
    int   result;
    int   time;
    /* using b-direction list
    struct Entry* next_user;
    struct Entry* next_item;
    struct Entry* next_time;
    struct Entry* pre_user;
    struct Entry* pre_item;
    struct Entry* pre_time;
    */
};
typedef struct Entry Entry;
#endif
// function
void buildStruct(std::list<Entry> *);

void printEntry(Entry &entry); // print will cost much time
int mapStringInteger(std::string s);

int accept(int u, int i, int t);
void items(int u1, int u2);
void users(int i1, int i2, int t1, int t2);
double ratio(int i, int threshold);
void findtime_item(int i, int U[]); // Users implemented in different ways.
