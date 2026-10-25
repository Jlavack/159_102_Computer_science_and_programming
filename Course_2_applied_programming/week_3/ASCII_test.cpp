#include <iostream>
using namespace std;
char a, b, c; //swap between int and char for testing

int main() {
  a = 126; //decimal
  b= 0x7E; //hex
  c = 01111110; //binary
  //c = c >> 2;

//-------------------print--------------------------//
  cout << "a as character is " << (char) a << "." <<endl; // fullstop to identify if a space etc is printed
  cout << "a integer is " << (int) a << endl;
  cout << "b as character is " << (char) b << "." <<endl;
  cout << "b as integer is " << (int) b << endl;
  cout << "c as character is " << (char) c << "." <<endl;
  cout << "c as integer is " << (int) c << endl;


}
