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
Node* createnode(int num);
Node* listpointer;
int main() {
 Node* firstnode;
 listpointer = NULL;
 firstnode = createnode(45);
 listpointer = firstnode;
}
Node* createnode(int num) {
 Node* temp;
 temp = new Node;
 temp->loaddata(num, NULL);
 return temp;
}
//---------- methods for the Node ---------
void Node::loaddata(int v, Node* p) {
 value = v;
 next = p;
}
