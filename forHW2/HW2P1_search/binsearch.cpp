using namespace std;
#include <iostream>
#include "math.h"

//--------------------------------------------
// CS311 HW2P1 Binary Search
// Name: Asma Ahmed
// Compiler: g++
// --------------------------------------------

// x is what we are looking for in L; first and last are slot numbers 
int binarySearch(int L[], int x, int first, int last) 
{
  int middle = floor(first+last)/2; //if first == las, there is only on element

  cout << "comparing against an element in slot " << middle << endl;

  if(x == L[middle])
    return middle; // found x at location middle, so return the location
  else if(first == last)
    return -1; // if not found, return -1
  else if(x < L[middle])
    last = middle - 1; // go to first half
  else if(x > L[middle])
    first = middle + 1; // go to second half

  return binarySearch(L,x,first,last); // recursive call
}


int main()
{
  int A[10];
  int e;  // to look for this
  int n = 10;
  int myfirst = 0;
  int mylast = n-1;

  // fixed elements for A
  A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;

  cout << "What do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A
  int respos = binarySearch(A, e, myfirst, mylast);

  if (respos == -1) cout << "Element not found" << endl; 
  else cout << "Found it in position " << respos+1 << endl;

}
