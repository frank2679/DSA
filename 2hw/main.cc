#include <iostream>
#include <string>
using namespace std;

struct Entry
{
    int   user;
    int   item;
    int   result;
    int   time;
};

/*
void formEntry(struct Entry *entry, int a[] )
{
    entry->user = a[0];
    entry->item = a[1];
    entry->time = a[3];
    entry->result = a[2];
}
*/

void printEntry(struct Entry &entry) // print will cost much time
{
    cout << entry.user << ' ';
    cout << entry.item << ' ';
    cout << entry.result << ' ';
    cout << entry.time << ' ';
    cout << endl;
}   

int main()
{
    int a[4] = {0};
    struct Entry entry;
    struct Entry &r = entry;
    // input data & build data structure
    for (int i = 0; i < 10 /* (cin >> a[0])*/ ; i++)
    {
        for(int j = 0; j < 4; j++)
            cin >> a[j];

        entry.user = a[0];
        entry.item = a[1];
        entry.result = a[2];
        entry.time = a[3];
        printEntry(r);
    }
/*
    string s; 
    cin >> s;
    if(s == 'a')
        cout << "accept" << endl;
        */
    return 0;
}
