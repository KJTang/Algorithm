#include <iostream>

#include "hashtable.h"

using namespace std;

int main() {
    myHashTable<int> test;
    test.add("000", 0);
    test.add("1", 1);
    test.add("2", 2);
    test.add("3", 3);

    cout<<test.find("2", -1)<<endl;
    test.remove("2");
    cout<<test.find("2", -1)<<endl;

    return 0;
}