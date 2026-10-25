#include <iostream>
using namespace std;

int main() {
  int x, y, a, b, c;
x = 3;
y = 5;
a = x & y;
b = x|y;
c = x ^ y;

unsigned int k, m;
k = 33; // k = 0010 0001
m = ~k; // m = 1101 1110 = DE16 = 13*16 + 14 = 222_10

int z, n;
z = 17;
n = ~z + 1; // m will now have the value -17


cout << a << endl;
cout << b << endl;
cout << c << endl;
cout << m << endl;
cout << n << endl;
}
