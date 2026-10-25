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
void displaylist();

Node* listpointer;

int main() {
   Node *current, *prevnode, *nextnode, *previous, *temp;
   int i, x;
   listpointer = NULL;

   //prompt to enter list
   cout << "Enter five values to the linked list \n";

   // insert four nodes in the list
   for (i = 0; i < 5; i++) {
     cin >> x;
     temp = new Node;
     temp->loaddata(x, listpointer);
     listpointer = temp;
   }
  displaylist();
  cout << endl;

  //prompt to ask which node to delete.
  int searchvalue, currentvalue;
  bool found;
  cout << "Which value should be removed? \n";
  cin >> searchvalue;

  //removing the value
  found = false;
  previous = NULL;
  current = listpointer; //intitalise current as listpoints
  while (current != NULL) { // current is not empty (should not happen unless deleted)
    currentvalue = current->getvalue(); // gets the value of current node, without it the program finds no number and returns found == false result.
    if (currentvalue == searchvalue) { //checks if matches the entered value
      found = true;
      temp = current; //equates the pointer temp to the found value
      prevnode = previous; //equates previous node pointer to the value of *previous. Makes them equal
    }
    previous = current; // equates previous to current, also shared by temp
    current = current->getnext(); // points current to the next value in the list, iterating along the list
  }
  if (found == false) {
    cout << "Search value not listed \n";
    exit(1);
  }
  previous = prevnode;
  nextnode = temp->getnext(); //points nextnode to the one after the one after temp, without it the list behind and including the number selected are removed.
  if (previous == NULL) { //first node
    listpointer = nextnode;//iterates along list, without this line, the first vlaue can't be deleted.
  } else { //if previous != NULL
    previous->setnext(nextnode); //points previous the next node after temp, deleteing temp.
  }
  delete temp;
  displaylist();
   cout << endl;
}

//-----------------functions-------------------------------------------------//
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
 //---------- methods for the Node ---------
 void Node::loaddata(int v, Node* p) {
  value = v;
  next = p;
 }
