/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/


/* NOTE:
to run tests:
    cd hw1
    g++ split.cpp test_split.cpp -o test_split
    ./test_split
*/


/* NOTE:
valgrind commands:
g++ split.cpp test_split.cpp -o program
valgrind --tool=memcheck --leak-check=yes ./program input.txt output.txt

*/

#include "split.h"
#include <iostream>

using namespace std;

void enumerate(Node* head){
  while (head!= nullptr){
    cout << head->value << "  ";
    head = head->next;
  }
  cout << endl;
  cout << endl;
}
int main(int argc, char* argv[])
{
  /*
  Node* head = new Node (5, nullptr);
  head = new Node (4, head);
  head = new Node (3, head);
  head = new Node (2, head);
  head = new Node (1, head);
*/
  Node* head = new Node (9, nullptr);
  head = new Node (8, head);
  head = new Node (7, head);
  head = new Node (6, head);
  head = new Node (5, head); 
  head = new Node (4, head);
  head = new Node (3, head);
  head = new Node (2, head);
  head = new Node (1, head);


  Node* odds = nullptr;
  Node * evens = nullptr;

  split (head, odds, evens);
  
  enumerate(odds);
  enumerate(evens);

  //deleting mem allocation
  while (odds != nullptr){
    Node* temp = odds;
    odds = odds->next;
    delete temp;
  }
  while (evens != nullptr){
    Node* temp = evens;
    evens = evens->next;
    delete temp;
  } 
  return 0;
}
