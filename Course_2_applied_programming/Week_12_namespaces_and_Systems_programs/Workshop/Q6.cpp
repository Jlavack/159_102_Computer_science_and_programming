#include <iostream>
using namespace std;
void thing();
int main() {
 thing();
}
void thing() {
 int value;
 cout << value << endl;
}

//value is unitialised. So will be a random number. Often the program will display 0. 
