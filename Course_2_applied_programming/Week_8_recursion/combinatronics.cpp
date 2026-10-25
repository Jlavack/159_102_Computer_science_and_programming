#include <iostream>
using namespace std;

int factorial(int x);

int main() {
 int n, r, result;
 cout << "Enter the number of items, n= ";
 cin >> n;
 cout << "Enter the number of items to select, r= ";
 cin >> r;

 result = factorial(n) / (factorial(r) * factorial(n - r));
 cout << "The number of ways to select " << r << " items from a set of " << n << " items is: " << endl;
 cout << "C(n, r) = " << result << endl;
}

int factorial(int x) {
 int result;
 if (x == 0) {
 return 1; // the base case

 }
 //cout << x << ", ";
 result = x * factorial(x - 1);
 return result;
}
