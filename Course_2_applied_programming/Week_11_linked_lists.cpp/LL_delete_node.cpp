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
 Node *temp, *temp2, *previous;
 int i;
 listpointer = NULL;
 // insert three nodes in the list
 for (i = 0; i < 3; i++) {
 temp = new Node;
 temp->loaddata(i * 10, listpointer);
 listpointer = temp;
 }
 displaylist();
 cout << endl;
 // now remove the second node
 temp = listpointer->getnext(); // the second node
 temp2 = temp->getnext();
 previous = listpointer;
 previous->setnext(temp2);
 delete temp; // delete the node to free memory
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
