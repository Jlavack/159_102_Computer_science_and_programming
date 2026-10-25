#include <iostream>
using namespace std;
int factorial(int x);
int main() {
 int n, f;
 cout << "Enter a positive integer value ";
 cin >> n;
 f = factorial(n);
 cout << "The factorial of " << n << " is " << f << endl;
}
int factorial(int x) {
 int result;
 if (x == 0) {
 return 1; // the base case

 }
 cout << x << ", ";
 result = x * factorial(x - 1);
 return result;
}
