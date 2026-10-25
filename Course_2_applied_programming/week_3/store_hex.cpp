#include <iostream>
using namespace std;
char value;
int main() {
 value = 0x36; // this means load with hexadecimal value 36
 cout << "Value is " << (int)value << endl; //(int) converts to integer from char.
}

/*
#include <iostream>
using namespace std;
int value;
int main() {
 value = 0x41; // this means load with hexadecimal value 41
 cout << "Value is " << value << endl;
}
*/
