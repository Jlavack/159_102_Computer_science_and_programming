#include <iostream>
using namespace std;
class Node {
private:
  int value;
 // you can include more data items here
  Node *next;
public:
   void loaddata(int v, Node* p);
   int getvalue() { return value; }
   Node* getnext() { return next; }
   void setvalue(int v) { value = v; }
   void setnext(Node* p) { next = p; }
};
//functions prototypes--------------------------------------------------------//
void displaylist();
//classes---------------------------------------------------------------------//
Node* listpointer;
//Main------------------------------------------------------------------------//
int main() {
   Node *temp;
   int number;
   listpointer = NULL;
   number = 999; // make sure number is > zero
   while (number >= 0) {
     cout << "Enter an integer value (-1 to stop) ";
     cin >> number;
     if (number >= 0) {
       temp = new Node;
       temp->loaddata(number, listpointer);
       listpointer = temp;
     }
   }
   displaylist();
}
//-----------------------functions--------------------------------------------//
void displaylist() {
 Node* current;
 int currentvalue;
 current = listpointer;
 while (current != NULL) {
 currentvalue = current->getvalue();
 cout << currentvalue << ", ";
 current = current->getnext();
 }
}

//---------- methods for the Node --------------------------------------------//
void Node::loaddata(int v, Node* p) {
 value = v;
 next = p;
}
