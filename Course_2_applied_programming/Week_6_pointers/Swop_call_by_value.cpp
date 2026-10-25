#include <iostream>
using namespace std;
void swop(string *ptr1, string *ptr2);
int main() {
  string a, b;
  a = "Fish";
  b = "Clam";
  cout << "a is " << a << " and b is " << b << endl;
  swop(&a, &b);
  cout << "a is " << a << " and b is " << b << endl;
}
void swop(string *ptr1, string *ptr2) {
// swop the contents of ptr1 and ptr2
 string temp;
 temp = *ptr1;
 *ptr1 = *ptr2;
 *ptr2 = temp;
}
