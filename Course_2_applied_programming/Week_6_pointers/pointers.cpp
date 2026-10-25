#include <iostream>
using namespace std;
int k;
int *ptr; //the asterix defines the integer pointer as a value at a location

int main() {
 k = 17;
 ptr = &k; //defines the variable as the location of k
 cout << "The value in k is " << k << endl;
 cout << "The address of k is " << ptr << endl;
 cout << "The data at the address " << ptr << " is ";
 cout << *ptr << endl; //prints values at locaiton stored as variable 'ptr'
}
