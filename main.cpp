#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <errno.h>
#include <stdlib.h>
#include <limits.h>

#include "hash_table.cpp"
#include "hash_item.cpp"
using namespace std;

int main( int argc, char* argv[]) {
    HashTable       hashtable(2000 );
    __ItemType      item;



    // 1 successful insert 0 duplicate
    item.set("BOB", 1);
    hashtable.insert(item);
    item.set("BoB",91);
    hashtable.insert(item);
    item.set("Billy", 1);
    hashtable.insert(item);
    item.set("Joey", 2);
    hashtable.insert(item);
    item.set("Lily", 3);
    hashtable.insert(item);
    item.set("Jessica", 4);
    hashtable.insert(item);
    item.set("Asbur", 5);
    hashtable.insert(item);
    item.set("liLy",5);
     hashtable.insert(item);   // should be 0 here cus Bob already inserted
    item.set("Lily",9);
     hashtable.insert(item);   // should be 0 here cus Bob already inserted
    item.set("Mohammad",4);
     hashtable.insert(item);
    item.set("Johnny",7);
     hashtable.insert(item); // 1 here
    item.set("Johnny",5);
     hashtable.insert(item); // 0 here


    cout << "___________________" << endl;
     hashtable.listall( cout );

    cout << "table size : " << hashtable.size()<< endl;

   cout << "___________________" << endl;

    //     // 1 successful insert 0 duplicate
    // item.set("Bob", 1);
    // hashtable.remove(item);
    // hashtable.listall( cout );
    // cout << "table size : " << hashtable.size()<< endl;
    // cout << "___________________" << endl;

// item.set("asbur", 700);
// cout << hashtable.find(item) << endl;
    item.set("billy", 2);
    hashtable.remove(item);
    hashtable.listall( cout );
        cout << "table size : " << hashtable.size()<< endl;
        cout << "___________________" << endl;

    // item.set("Billy", 1);
    // cout <<hashtable.remove(item)<<endl;
    // hashtable.listall( cout );
    // item.set("Lily", 3);
    // cout <<hashtable.remove(item)<<endl;
    // hashtable.listall( cout );
    // item.set("Jessica", 4);
    // cout <<hashtable.remove(item)<<endl;
    // hashtable.listall( cout );
    // item.set("Asbur", 5);
    // cout <<hashtable.remove(item)<<endl;
    // hashtable.listall( cout );
    // item.set("Mohammad",4);
    // cout << hashtable.remove(item)<<endl;
    // hashtable.listall( cout );
    // item.set("Johnny",7);
    // cout << hashtable.remove(item) << endl; // 1 here
    // hashtable.listall( cout );
    // item.set("Johnny",5);
    // cout << hashtable.remove(item) << endl; // 0 here
//    cout << hashtable.remove(item) << endl;
item.set("joey",5);
   cout <<hashtable.find(item) << endl;

    // // ostream & out; 
    // hashtable.print();
    // cout << "___________________" << endl;
    // cout << hashtable.size()<< endl;


    return 0;
}
