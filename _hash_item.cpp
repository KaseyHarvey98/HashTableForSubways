/******************************************************************************
  Title          : _hash_item.cpp
  Author         : Kasey Harvey
  Created on     : April 6, 2019
  Description    : Defines an item type that can be used in the project
  Purpose        : To define the item type to be hashed
  Usage          :
  Build with     :
  Modifications  :
     4/4/2019 by SW


******************************************************************************/
#include "_hash_item.h"
#include <vector>
#include <string>
#include <cctype>
#include <iostream>
using namespace std;
//Helper Functions

/* ConvertLower(str s)
 * @note takes a string and makes it case insensitive
 * @param s is a string
 * @post string is made case insensitive
*/
string ConvertLower( string s ){
    string caseinsen ;
    for(int i = 0; i < s.length(); i++)
    {
        caseinsen += (char)tolower(s[i]);
    }
    return caseinsen;
}
__ItemType::__ItemType(){
    name     = "";
    position = -1;
}
void __ItemType::set(string s , int pos){
  name     = s;
  position = pos;
}

void __ItemType::get(string & s, int & pos){
    s   = name;
    pos = position;
}

bool __ItemType::operator==( __ItemType rhs) const{
    if(ConvertLower(name) == ConvertLower(rhs.name)) return true;
    return false;
}
unsigned int __ItemType::code(){
    int encrypt = 0;
    for (int i = 0; i < name.length(); i++)
    {
        encrypt += (unsigned int)name[i];
    }
    return encrypt;
}

ostream &  operator<<( ostream & os, __ItemType item ){
    os << item.name << " " << item.position;
     return os ;
}
for auto 
