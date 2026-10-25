#include <iostream>
using namespace std;
void swop(int & x, int & y);
int main() {
 int a, b;
 a = 3;
 b = 5;
 cout << "a is " << a << " and b is " << b << endl;
 swop(a, b);
 cout << "a is " << a << " and b is " << b << endl;
}
void swop(int & x, int & y) {
// swop the contents of x and y
 int temp;
 temp = x;
 x = y;
 y = temp;
}
