#include <iostream>
using namespace std;
unsigned char c, mask, result;
int main() {
 c = 10111011; // this is the number you are testing
 cout << "C is: " << c << endl;
 mask = 0x80; // 1000 0000
 result = c & mask;
 if (result == 0) {
 cout << "The most significant bit is 0\n";
 } else {
 cout << "The most significant bit is 1\n";
 }
}
