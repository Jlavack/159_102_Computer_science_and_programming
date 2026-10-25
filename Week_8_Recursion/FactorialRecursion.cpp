// Factorial Formula: n! = n(n - 1)(n - 2) ... 2..1
// Factorial of 4: 4! = 4*3*2*1
// Factorial of 5: 5! = 5 * 4!

#include <iostream>
using namespace std;

int factorial(int);

int main() {
    int n, result;

    cout << "Enter a non-negative number: ";
    cin >> n;

//// Iteration approach
    result=1;
    for(int i=0;i<=n;i++){
      result=result*i;
    }

//// Recursion approach
    //result = factorial(n);
    cout << "Factorial of " << n << " = " << result << endl;
    return 0;
}

int factorial(int n) {
    if (n > 1) {
        return n * factorial(n - 1);
    } else {  // base case if(n <= 1)
        return 1;
    }

    //return n * factorial(n - 1);
}
