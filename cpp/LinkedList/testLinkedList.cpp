#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    List<int> intlist;
    intlist.addfirst(5);
    intlist.addfirst(10.0);
    intlist.addlast(15.0);
    intlist.print();

    int first = intlist.returnfirst();
    int last = intlist.returnlast();
    int count = intlist.entries();

    cout << first << " " << last << " " << count << endl;
    
    intlist.removefirst();
    intlist.removelast();
    intlist.print();
    
    return 0;
}