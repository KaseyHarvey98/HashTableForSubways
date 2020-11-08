/******************************************************************************
  Title          : hash_table.cpp
  Author         : Kasey Harvey
  Created on     : April 6, 2019
  Description    : Interface description for a hash table class
  Purpose        : To define the minimal requirements of a hash table
  Usage          : Derive a concrete hash table class from this interface
  Build with     : no building
  Modifications  :
      4/4/2019 by SW
      The constructor for the abstract class was removed. Abstract classes
      cannot have constructors. (I should have known that!)



******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "hash_table.h"

using namespace std;

vector<int> codes; // list of encypted codes used

HashTable::HashTable(){
    hash_item_count_ = 0;
    capacity_        = INITIAL_SIZE;
    hash_table_[capacity_];
}
HashTable::HashTable(int n){
    hash_item_count_ = 0;
    capacity_        = n;
    hash_table_[capacity_];
}
int HashTable::find( __ItemType & item ) const {
    // __ItemType *entry = hash_table_[hash_value]; to use nodes
    for(int i = 0; i != capacity_; i++)    {
        if (item == hash_table_[i])return 1;
     }
    return 0;
}
int HashTable::insert ( __ItemType item   ) {
    unsigned int hash_value = (item.code() % capacity_);
    string key;
    int pos;
    bool collision;

    item.get(key,pos);

    for(int i = 0; i != capacity_; i++){
            if (item == hash_table_[i]) return 0;
    }

    // collision resolution
    for(int i = 0; i < codes.size(); i++){
        if (codes[i] == hash_value) {
            collision = true;
        }
        
    }
    while (collision){
        for(int i = 0; i < codes.size(); i++){
            if (codes[i] != hash_value) collision = false;
            if(i == (codes.size() -1)) collision = false;
        }

        hash_value ++;
    }
    // end collision resolution 

    hash_table_[hash_value].set(key, pos);
    hash_item_count_++;
    codes.push_back(hash_value);
    return 1;

}
int HashTable::remove ( __ItemType  item ) {
    unsigned int hash_value = (item.code() % capacity_);

    for(int i = 0; i != capacity_; i++){
         if (item == hash_table_[i]) {
            hash_table_[i].set("", -1);
            hash_item_count_ --;

            // delete fron codes 
            for(int j = 0; j < codes.size(); j++){
                if (codes[j] == i ) codes.erase(codes.begin()+j);
            }
            return 1;
        }            
    }
  return 0;
}
int HashTable::size() const {
    return hash_item_count_;
}
int HashTable::listall ( ostream & os ) const {
    string key = "";
    int pos   = 0;
    int total = 0;
    for(int i = 0; i != capacity_; i++){
        hash_table_[i].get(key, pos);
        if(!key.empty()){
            os << hash_table_[i];
            os << endl;
            total++;
        }
    }
    return total;
}
