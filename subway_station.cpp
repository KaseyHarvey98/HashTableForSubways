 /******************************************************************************
  Title          : _subway_station.cpp
  Author         : Kasey Harvey
  Created on     : April 21, 2018
  Description    : Implementation file for the SubwayStation object
  Purpose        : Encapsulates data and methods of a subway portal
  Usage          :
  Build with     :
  Modifications  :

******************************************************************************/
#include <list>
#include <set>
#include <string>
#include <string.h>
#include "subway_portal.h"
#include "subway_station.h"
    /** SubwayStation() is a default constructor
     *  It should initialize any private members with suiatbel default values. 
     * int          m_parent_id;
    set<string>  m_station_names;        
    list<int>    children;
    string       portal_unique_name;
    SubwayPortal portal;        
     */
SubwayStation::SubwayStation(){
     m_parent_id = 0;
     set<string>  m_station_names;        
     portal_unique_name= "";
}
     /** This is a constructor that creates a SubwayStation object from a portal
      *  It makes the portal the embedded portal.
      */
SubwayStation::SubwayStation(SubwayPortal portal ){

}
    /** set_parent() sets the parent id of the station
     *  @param int [in] the id of the parent
     */
void  SubwayStation::set_parent(int newparent){
     m_parent_id = newparent;

}
     /** add_child() adds a new child to the station's list of children
      *  @param int [in] the index of the child to add
      */
void  SubwayStation::add_child(int child){
     children.push_back(child);

}
     /** A friend function that determines when two stations are connected
      *  @param SubwayStation [in] s1
      *  @param SubwayStation [in] s2
      *  @return bool true iff s1 and s2 are connected according to rules defined
      *               in the assignment specification
     */
bool connected(SubwayStation s1, SubwayStation s2){

}
     /** add_station_name() adds a new name to station
     *  @Note:  It does not add a name if it is already in the set of names for
     *          the station.
     *  @param  string [in] newname is name to be added
     *  @return 1 if name is added and 0 if not
     */
int SubwayStation::add_station_name(string newname){

}
    /** names() returns a list of the names of the station as a list of strings
     */
list<string> SubwayStation::names()  const{
     list<string> list_names;
     set<string>::iterator sub_names = m_station_names.begin();
     while (sub_names != m_station_names.end())
     {
          list_names.push_back(*sub_names);
     }
     return list_names;
}
 // primary_name() is the first station name in its set of names
string  SubwayStation::primary_name() const{
     set<string>::iterator sub_names = m_station_names.begin();
     return *sub_names;
}
     // parent_id() is the index in the array of the parent of the station
int   SubwayStation::parent_id() const{

}
     /** portal_list() returns a list of the ids in the list of the portals in
      * this station set
      */
list<int>   SubwayStation::portal_list() const{

}
    // returns the name of the embedded portal
string  SubwayStation::portal_name() const{

}
    // returns the portal that is embedded in this station object
void SubwayStation::get_portal(SubwayPortal & ) const{

}