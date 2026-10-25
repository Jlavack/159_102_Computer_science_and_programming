#include <iostream>
#include <cstdio>  // to use getchar
using namespace std;

class Node {
private:
  string name;
  int phone;
  Node *next;
public:
  void loaddata(string n, int pn, Node* p);
  string getname() { return name; }
  int getnumber() { return phone; }
  Node* getnext() { return next; }
  void setnext(Node* p) { next = p; }
};

void enterdata();
void searchlist(string str);

Node* listpointer;

int main() {
  string search;
  listpointer = NULL;
  enterdata();
  cout << "\nEnter the name to search for ";
  getline(cin, search);
  searchlist(search);
}
//--------------------functions-----------------------------------------------//
void enterdata() {
  Node *nextnode;
  string name;
  int phonenumber, number;
  number = 999; //initialise number so it doesn't randomly get 0
  while (number >= 0) {
    nextnode = new Node; //set aside space for the next node
    cout << "Enter a name and phonenumber, ?? to stop. \n";
    cout << "Name: ";
    getline(cin, name);
    if (name == "??") {//check for exit condition
      break;
    }
    cout << "Number: ";
    cin >> phonenumber;
    getchar(); //clear input buffer
    nextnode->loaddata(name, phonenumber, listpointer); //append the next node to the list
    listpointer=nextnode;//set listpoint to the next node
  }
}

void searchlist(string str) {
  Node* current;
  string currentname;
  current = listpointer;
  while (current != NULL) {
    currentname = current->getname();
    if (currentname == str) {
      cout << "Phone number for " << currentname;
      cout << " is " << current->getnumber() << endl;
      return;
    }
    current->getnext();
  }
  cout << str << " is not in the list.\n";
}

//---------- methods for the Node ---------
void Node::loaddata(string n, int pn, Node* p) {
  name = n;
  phone = pn;
  next = p;
}
