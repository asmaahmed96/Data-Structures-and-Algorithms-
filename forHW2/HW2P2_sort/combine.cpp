using namespace std;
#include <iostream>
#include <vector>

//--------------------------------------------
//CS311 HW2P2 Combine 
//Name: Asma Ahmed
//Compiler: g++
//--------------------------------------------

// combine two sorted lists A and B into R
// displays comparison every time it is done
void combine( vector<int> A, vector<int> B, vector<int> &R )
{
  int a = 0;
  int b = 0;
  int r = 0;
  int Acount = A.size();
  int Bcount = B.size();  
  while(Acount > 0 && Bcount > 0)
    {
      if(A[a] < B[b])
	{
	  R.push_back(A[a++]);
     	  --Acount;
	}
      
      else
	{
	  R.push_back(B[b++]);
       	  --Bcount;
	}
      
      cout << "comparison" << endl;
    } // be careful -- R comes in as an empty vector
  if(Acount != 0)
    {
      while(Acount > 0)
	{
	  R.push_back(A[a++]);
       	  --Acount;
	}
    }
  else if(Bcount != 0)
    {
      while(Bcount > 0)
	{ 
	  R.push_back(B[b++]);
      	  --Bcount;
	}
    }
}
 


int main()
{  
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int N;  // how many elements in each of L1 and L2
  int e;  // for each element

  cout << "How many elements in each list?" << endl;
  cin >> N;

  cout << "List1"  << endl;
  for (int i = 1; i <=N; i++)
    { 
      cout << "element :"; 
      cin >> e; 
      L1.push_back(e);
    } 

  cout << "List2"  << endl; 
  for (int i = 1; i <=N; i++)
    {
      cout << "element :";
      cin >> e;
      L2.push_back(e);
    } 
  

  // call combine here to combine L1 and L2 into L3
  combine(L1, L2, L3);
  
  cout << "The result is: ";
  for (int i = 0; i < N*2; i++)
    {
      cout << L3[i]; 
    }
  cout << endl;

}// end of main
