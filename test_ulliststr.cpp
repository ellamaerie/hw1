#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

/* NOTE : (this is for easier run testing)
g++ ulliststr.cpp test_ulliststr.cpp -o test_ulliststr
./test_ulliststr
*/
using namespace std;

int main(int argc, char* argv[])
{
  ULListStr l; // list

  // testing push_back()
  l.push_back("Pink");
  l.push_back("Blue");
  l.push_back("White");

  cout << "push_back function: ";
  for (size_t i = 0; i < l.size(); i++){
    cout << i << " ";
  }
  cout << endl;

  // testing push_front()
  l.push_front("Green");
  l.push_front("Purple");
  l.push_front("Red");

  cout << "push_front function: ";
  for (size_t i = 0; i < l.size(); i++){
    cout << i << " ";
  }
  cout << endl;

  // front()
  cout << "front: " << l.front() << endl;

  // back()
  cout << "back: " << l.back() << endl;

  //pop_front()
  cout << "pop_front function: ";
  l.pop_front();

  for (size_t i = 0; i < l.size(); i++){
    cout << i << " ";
  }
  cout << endl;

  //pop_back()
  l.pop_back();
  cout << "pop_back function: ";

  for (size_t i = 0; i < l.size(); i++){
    cout << i << " ";
  }
  cout << endl;

  // front()
  cout << "front: " << l.front() << endl;

  // back()
  cout << "back: " << l.back() << endl;

}