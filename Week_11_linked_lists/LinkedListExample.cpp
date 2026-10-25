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

void displaylist(); // display nodes
void recursiondisplaylist(Node* current); // display nodes in reverse order
void addToBeginning(int value); // add a node to the beginning
void addToEnd(int value); // add a node to the end of a list that contains more than one node
void insertAfter(int value, int nodeNumber); // insert a node after the posiiton of nodeNumber
void removeNode(int nodeNumber); // remove the node at the position of nodeNumber
void removeNodeByValue(int nodeValue); // remove the node with nodeValue

Node* listpointer;

int main() {
  Node *temp;
  int number;
  listpointer = NULL;
  for (number=3; number>0; number--) {
    temp = new Node;
    temp->loaddata(number, listpointer);
    listpointer = temp;
    //addToBeginning(number);
    //addToEnd(number);
  }
  //addToBeginning(4);
  //addToEnd(4);
  insertAfter(4,3);
  //removeNode(1);
  removeNodeByValue(2);
  displaylist();
  //recursiondisplaylist(listpointer);
}

/// Add a new node at the beginning of the list
void addToBeginning(int value){
  Node *temp = new Node;
  temp->loaddata(value, listpointer);
  listpointer = temp;
}

/// Add a new node at the end of the list
/// The list can be an empty list or has more than one nodes
void addToEnd(int value){
  Node* lastnode = listpointer;
  Node *temp = new Node;
  temp->loaddata(value, NULL);

  if(lastnode != NULL){
    while (lastnode->getnext() != NULL) {
      lastnode = lastnode->getnext();
    }
    lastnode->setnext(temp);
  }else{
    listpointer = temp;
  }
  lastnode = temp;
}

/// insert a new node after a node that is at the position of nodeNumber
/// nodeNumber must be in the range of 1 ... n, n is the size of the list
void insertAfter(int value, int nodeNumber){
  int i = 0;
  Node* nodebefore;
  Node* nodeafter;
  Node* current = listpointer;
  while (current != NULL) {
    i++;
    if(i == nodeNumber){
      nodebefore = current;
      nodeafter = current->getnext();
      break;
    }
    current = current->getnext();
  }
  Node *temp = new Node;
  temp->loaddata(value, nodeafter);
  nodebefore->setnext(temp);
}

/// remove a node that is at the position of nodeNumber
/// nodeNumber must be in the range of 1 ... n, n is the size of the list
void removeNode(int nodeNumber){
  int i = 0;
  bool found = false;
  Node *nodebefore, *nodeafter, *temp;
  Node* current = listpointer;
  while (current != NULL) {
    i++;
    if(i == nodeNumber-1){
      nodebefore = current;
    }
    if(i == nodeNumber){
      temp = current;
      found = true;
      if(nodeNumber == 1){
        listpointer = temp->getnext();
        delete temp;
        return;
      }
    }
    if(i == nodeNumber+1){
      nodeafter = current;
      break;
    }
    current = current->getnext();
  }
  if(found){
    nodebefore->setnext(nodeafter);
    delete temp;
  }
  else{
    cout << nodeNumber << " is out of the size range" << endl;
  }
}

/// remove a node that's value is nodeValue
void removeNodeByValue(int nodeValue){
  int i = 0;
  bool found = false;
  Node *nodebefore, *nodeafter, *temp;
  Node* current = listpointer;
  while (current != NULL) {
    i++;
    if(current->getvalue() == nodeValue){
      temp = current;
      nodeafter = current->getnext();
      found = true;
      if(i == 1){
        listpointer = nodeafter;
        delete temp;
        return;
      }
      break;
    }
    nodebefore = current;
    current = current->getnext();
  }
  if(found){
    nodebefore->setnext(nodeafter);
    delete temp;
  }
  else{
    cout << nodeValue << " is not in the list" << endl;
  }
}

/// display nodes in the list
void displaylist() {
  Node* current;
  current = listpointer;
  while (current != NULL) {
    cout << current->getvalue() << ", ";
    current = current->getnext();
  }
  cout << endl;
}

/// display nodes in reverse order
void recursiondisplaylist(Node* current) {
  if(current == NULL){
    return;
  }
  //cout << current->getvalue() << ", "; // same as displaylist()
  recursiondisplaylist(current->getnext());
  cout << current->getvalue() << ", "; // print nodes in reverse order
}

//---------- methods for the Node ---------
void Node::loaddata(int v, Node* p) {
  value = v;
  next = p;
}
