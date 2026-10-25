#include <iostream>
#include <list>
using namespace std;
void displaylist(list<int> l);
list<int> mylist;
int main() {
 int value;
 value = 999; // ensure that value > zero
 while (value >= 0) {
 cout << "Enter an integer value (-1 to stop) ";
 cin >> value;
 if (value >= 0) {
 mylist.push_back(value);
 }
 }
 displaylist(mylist);
}
void displaylist(list<int> l) {
 list<int>::iterator ptr;
 for (ptr = l.begin(); ptr != l.end(); ptr++) {
 cout << *ptr << ", ";
 }
 cout << endl;
}
