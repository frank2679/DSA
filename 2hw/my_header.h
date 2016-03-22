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
#endif
// function
#ifndef _BUILD_STRUCTURE_H
#define _BUILD_STRUCTURE_H
void buildStruct(struct Entry*);
#endif

#include <string>
void printEntry(struct Entry &entry); // print will cost much time
int mapStringInteger(std::string s);
