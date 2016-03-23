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

int accept(std::list<Entry> *);
int items(std::list<Entry> *);
void users(std::list<Entry> *);
double ratio(std::list<Entry> *);
void findtime_item(std::list<Entry> *); // Users implemented in different ways.
