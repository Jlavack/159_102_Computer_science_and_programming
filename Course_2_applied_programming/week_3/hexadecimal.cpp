#include <iostream>
using namespace std;

int value;
char chr;
int main() {
 cout << "Enter a 2-digit hexadecimal number "; //2 digits is 8 bits in hex
 cin >> hex >> value; //'hex' command expects a hexadecimal number
 chr = value;
 cout << "Value is " << value << endl;
 cout << "Character is " << chr << endl;
 cout << "Hexadecimal value is ";
 cout << hex << uppercase << value << endl;
}
