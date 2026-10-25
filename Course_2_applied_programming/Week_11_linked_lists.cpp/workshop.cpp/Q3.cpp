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
   Node *ptr1, *ptr2, * ptr3, *ptr4, *temp;
   int i;
   listpointer = NULL;
   // insert four nodes in the list
   for (i = 0; i < 4; i++) {
     temp = new Node;
     temp->loaddata(i +1, listpointer);
     listpointer = temp;
   }
  displaylist();
  cout << endl;
 // now remove the third node
   ptr1 = listpointer; // ptr1 points to the first node
   ptr2 = ptr1->getnext(); // the second node
   ptr3 = ptr2->getnext(); // the third node
   ptr4 = ptr3->getnext(); // the fourth node
   // change node2 to point to node4
   ptr2->setnext(ptr4);
   delete ptr3; // delete node3 to free memory
   displaylist();
   cout << endl;
}



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
