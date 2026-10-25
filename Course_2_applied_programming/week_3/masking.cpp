#include <iostream>
using namespace std;

int x, mask, result;
int main() {
 x = 0x42; //(decimal 66) // try different numbers here
 mask = 0x20; //(mask with a one in the sixth bit)
 result = x | mask;
 cout << "x is " << (char) x;
 cout << " and result is " << (char) result << endl;
}
/*Set the sixth bit in a character (of 8 bits) to a one (mask = 32) to change a capital letter to a small letter.
Example: 'A' = 65 = 0100 0001. Now set the sixth bit = 0110 0001 = 97 = 'a'*/
