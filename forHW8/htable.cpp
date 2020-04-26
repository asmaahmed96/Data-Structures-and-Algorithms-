// CS311 Yoshii - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Asma Ahmed
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "htable.h"

htable::htable()
{}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
int htable::hash(int key)
{ 
  return key % TSIZE;
}

// adds the element to the table and returns slot#
int htable::add(el_t element )
{
  int slot = hash(element.key);  // hash with the key part
  table[slot].addRear(element);// Note that this means adding the element to a slist in the slot
  return slot;
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int skey)
{ 
  el_t E; //blank element
  int slot = hash(skey); // hash with skey
  el_t selement;  // this is the element to look for in slist
  selement.key = skey; // initialize selement with just the skey
  E = table[slot].search2(selement);// call slist's search2 with selement which returns the found element 
  return E;// return the found element from here (it could be blank)
}

// displays the entire table with slot#s too
void htable::displayTable()
{
  for (int i = 0; i < 37; i++)
    { cout << i << ":" ;   
      table[i].displayAll(); // call slist's displayAll
    }
}
