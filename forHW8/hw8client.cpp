// CS311 Yoshii - complete ** for HW8 client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Asma Ahmed
// File type: client hw8client.cpp (tester)
//===========================================

using namespace std;
#include "htable.h"

// This tester gets input data interactively but
// for a useful client, input should come from a file.
// Note that el_t X; will create a blank element X using the regular constructor.  
// Note that the second constructor of el_t can be used to
// create key+name to add to the table. e.g. el_t X(30, "mary");
int main()
{ 
  htable T;
  int key;
  string name;
  int stop = 1;
  int displayNum = 0;

  while(stop != 0)
    {  
      displayNum++;
      //Interactively add about 20 keys and names to the table,
      //making sure some of them  collide. (function add)
      //You can create el_t containing a key and name using a constructor.
      cout << "Enter key to add to table: ";
      cin >> key;
      cout << "Enter name to add to table: ";
      cin >> name;
      cout << endl;

      el_t A(key,name); //add key & name to element
      int slot = T.add(A); //add element to T table

      cout << "There are currently " << displayNum << " keys and names in the table" << endl;
      cout << "Enter 0 to stop adding elements to table" << endl;
      cout << "To continue adding elements to table enter 1: ";
      cin >> stop;
      cout << endl;
    }
  stop = 1;
  T.displayTable();//DisplayTable.
  while(stop != 0)
    {
    //Interactively look up names using keys. (function find)
    //Cout the key + name if found else (blank element was returned)
    //an error message. 
      cout << "Look for? ";
      cin >> key;

      el_t L = T.find(key);
      el_t blank;
      if(L == blank)
	cout << key << " was not found." << endl;
      else
	cout << "Found " << key << ": " << L << endl;
      cout << endl;
      cout << "Enter 0 to stop searching and end program" << endl;
      cout << "To continue searching enter 1: ";
      cin >> stop;
    }
  cout << endl;
  cout << "Ending program" << endl; 
}
