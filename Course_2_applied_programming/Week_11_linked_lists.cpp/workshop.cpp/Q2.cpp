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
   Node *temp, *lastnode;
   int number, i;
   listpointer = NULL;
   // set up the first node
   cout << "Enter the first integer value ";
   cin >> number;
   listpointer = new Node;
   listpointer->loaddata(number, NULL);
   lastnode = listpointer;
   // insert the other nodes
   for (i =0; i < 2; i++) {
     cout << "Enter an integer value (-1 to stop) ";
     cin >> number;
     temp = new Node;
     temp->loaddata(number, NULL);
     lastnode->setnext(temp);
     lastnode = temp;
   }
   displaylist();
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
