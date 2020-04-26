//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 

//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: Asma Ahmed
//Complier:  g++
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: Purpose of this program is to list all the possible compinations of this three letter string.
//Algorithm: Using a while loop, we will extract the first letter in the queue and display it and then pop back all three letters. We will continue to do this until the queue overflows. 

int main()
{
  queue Q; //make a queue
  // "A", "B", "C" in the queue 
  Q.add("A");
  Q.add("B");
  Q.add("C"); 
  // while loop -- indefinitely
  while(true)  
  {
      try
	{ 
	  string x; //local variable that will display the combinations

	  if(!Q.isEmpty()) //impilment while queue is not empty
	    {
	      Q.remove(x); //remove x from queue
	    }
	  cout << x << endl; //display x

	  if(!Q.isFull()) //impliment while queue is not full
	    {
	      Q.add(x + "A"); //add A back in queue
	      Q.add(x + "B"); //add B back in queue
	      Q.add(x + "C"); //add C back in queue
	    }
	  
	}
      catch(queue::Underflow) 
	{
	  cerr << "ERROR: Not enought phrases to try." ;
	  exit(1);
	}
      catch(queue::Overflow)
	{
	  cerr << "ERROR: Queue full. Cannot add phrase.";
	  exit(1);
	}// end of loop
  }
}

