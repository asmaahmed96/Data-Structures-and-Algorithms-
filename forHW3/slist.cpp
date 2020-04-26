// CS311 Yoshii Complete all functions with their comments                     // ====================================================                        //HW#: HW3P1 slist  inheriting from llist                                      //Your name: Asma Ahmed                                                        //Complier:  g++                                                               //File type: slist.cpp implementation file                                     //=====================================================                       

using namespace std;
#include<iostream>
#include"slist.h"

// ** Make sure llist constructor and destructors have couts in them           // do not change this one                                                       
slist::slist()
{
  cout << "slist constructor: " << endl;
}

// positions always start at 1                                                 
int slist::search(el_t key)
{
  Node *P = Front;
  int i = 1;
  while (P != NULL) // while list is not emty, continue 
    {
      if(P->Elem == key) //check to see if any node in list is Key
	{
	  return i; // if found return 
	}
      else // if not found incremnet i and go to next element in list
	{
	  i++;
	  P = P->Next;
	}
    }
  return 0;  
}

// don't forget to throw OutOfRange for bad pos                                
void slist::replace(el_t element, int pos)
{
  if(pos > Count || pos < 1) //if not in range of count and 1 then throw OutofRange
    {
      throw OutOfRange();
    }
  Node *temp = Front;
  int j = 1;
  while(j != pos) // while in range replace element with temp 
    {
      temp = temp->Next;
      j++;
    }
  temp->Elem = element;
}

bool slist::operator==(const slist& OtherOne)
{
  if(OtherOne.Count != this->Count) // if not the same length, retuen false
    {
      return false;
    }
  else 
    {
      Node *n1 = OtherOne.Front;
      Node *n2 = this->Front;
      while(n1 != NULL || n2 != NULL) // while list is not empty
	{
	  if(n1->Elem != n2->Elem) // check to see if the list are the same
	    {
	      return false; //if elements are not the same return false
	    }
	  // if same move to next node in list and repeat steps
	  n1 = n1->Next; 
	  n2 = n2 ->Next;
	}
      // if all the nodes are the same return true
      return true;
    }
}
