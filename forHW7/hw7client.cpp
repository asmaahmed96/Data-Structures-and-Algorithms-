//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Asma Ahmed
// File type: client hw7client.cpp 
//==========================================

// ** Be sure to include dgraph, slist and stack
#include <iostream>
#include "dgraph.h"
#include "stack.h"
using namespace std;

// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  // ** copy here the algorithm (read carefully) in the HW7
  // assignment sheet and use that has the comments. 
  //Display the graph before the DFS begins 
  dgraph G;//declare table object
  G.fillTable();//read in text file by calling fillTable
  G.displayGraph();//display graph
  slist List;//declare slist object for finding adjacency list of specified vertex
  //Push A onto the stack to start.
  stack S;//declare stack object
  int visitNum = 1;//to start A as 1
  char vertex = 'A';

  S.push(vertex);//push A onto stack
  // While the stack is not empty do:
  while(!S.isEmpty())
    {
      //Remove a vertex v from the stack.
      S.pop(vertex);
      //Display the vertex name.  E.G. “Removed B from stack”
      cout << "Removed " << vertex << " from stack" << endl;
      //If v is not marked yet (visit number is 0) then
      if(G.isMarked(vertex) == 0)
	{
	  //mark it (visit it **) and inform the user E.G. “Visit B as 2”
	  G.visit(visitNum, vertex);
	  cout << "Visit " << vertex << " as " << visitNum << endl;
	  //get its adjacency list
	  List = G.findAdjacency(vertex);
	  //if no adjacent ones inform the user E.G. “Deadend reached – backup”	
	  if(List.isEmpty())
	    {
	      cout << "Deadend reached - backup" << endl;
	    }
	  else //else put adjacent ones on the stack (delete from the rear and push) informing the user
	    {
	      cout << "... pushing ";
	      List.displayAll();
	      while(!List.isEmpty())
	      {
		List.deleteRear(vertex);
		S.push(vertex);
	      }
	    }
	  visitNum++;
	  
	}
      else // else inform the user E.G. “B had been visited already - backup.”
	{
	  cout << vertex << " has been visited already - backup" << endl;
	}
      //Display the stack clearly labeling it as the current stack
      cout << "Stack is: " << endl;
      S.displayAll();
    }// end of while loop
  //Display the Graph nicely with visit numbers for all vertices.
  G.displayGraph();
}// end of program
