#include <iostream>
using namespace std;

int mask, result;
char x;
int main() {
 cin >> x ; //(decimal 66) // try different numbers here
 mask = 0x20; //(mask with a one in the sixth bit)
 result = x | mask;
 cout << "x is " << (char) x;
 cout << " and result is " << (char) result << endl;
}
