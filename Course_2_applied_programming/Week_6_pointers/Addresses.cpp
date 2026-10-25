#include <iostream>
using namespace std;
int a;
int main() {
 a = 21;
 cout << "The value in a is " << a << endl;
 cout << "The address of a is " << &a << endl;
 cout << "The data at the address " << &a << " is ";
 cout << *(&a) << endl;
}
