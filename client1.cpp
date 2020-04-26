//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: Asma Ahmed
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: Purpose is to solve postfix equations.
//Algorithm: Using a while loop, we will check to make sure the user enters an oprend or operator, then add the oprends to the stack. Everytime an operator is found, two oprnds will be removed from the stack where they will then me added, subtracted, or multiplied, and then the result will be pushed back into the stack. 
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
     try
       {
	 item = expression[i];  // current char
	 
	 // ** do all the steps in the algorithm given in Notes-1
	 if(item >= '0' && item <= '9')
	   {
	     postfixstack.push(item - 48);
	   }
	 else if((item == '+') || (item == '-') || (item == '*'))
	   {
	     postfixstack.pop(box1);
	     postfixstack.pop(box2);

	     if (item == '-')
	       { 
		 box1 = box2 - box1;
	       }
	     else if (item == '+')
	       {
		 box1 = box2 + box1;
	       }
	     else if (item == '*')
	       {
		 box1 = box2 * box1;
	       }

	     postfixstack.push(box1); // result is pushed back to the stack
	   }
	 else throw "ERROR: Invalid element.";

       } // this closes try
     // Catch exceptions and report problems and quit the program now (exit(1)). 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{
	  cerr << "ERROR: Expression too long." << endl;
	  exit(1);
	}
      catch (stack::Underflow)
	{
	  cerr << "ERROR: Too few operands." << endl;
	  exit(1);
	}
      catch (char const* errormsg ) // for invalid item case
	{
	  cerr << errormsg << endl; 
	  exit(1);
	}

      // go back to the loop after incrementing i
     i++;
    }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.
  postfixstack.pop(box1);
  cout << "result: " << box1 << endl;
 // If anything is left on the stack, an incomplete expression 
 // was found so inform the user.
  if(!postfixstack.isEmpty())
    {
      cout << "ERROR: Incomplete expression." << endl;
    }

}// end of the program
