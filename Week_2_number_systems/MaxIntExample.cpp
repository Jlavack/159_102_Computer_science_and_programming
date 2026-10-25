#include <iostream>
#include <climits>
using namespace std;

int main(){
  cout<<INT_MAX<<endl;
  cout<<INT_MIN<<endl;
  int maxint = INT_MAX;
  int minint = INT_MIN;

  int a = maxint + 20; // integer overflow
  cout << "a = " << a << endl;

  int b = minint - 20; // integer underflow
  cout << "b = " << b << endl;
}
