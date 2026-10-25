#include <iostream>
using namespace std;

int square1(int n);   // Call-by-Value
void square2(int *n); // Call-by-Reference with Pointer Arguments
void square3(int &n); // Call-by-Reference with Reference Arguments

int a, b;

int main() {
    a = 3;
    b = 5;

//// Address operator &
    cout << "The value in a is " << a << endl;
    cout << "The value in b is " << b << endl;
    cout << "The address of a is " << &a << endl;
    cout << "The address of b is " << &b << endl;
    cout << endl;

//// Indirection Operator *
    // cout << "Value stored in address of a: " << *(&a) << endl;
    // cout << endl;

//// Pointers *
    // int *ptr;  // declare pointer variable
    // ptr = &a;  // store address of a in pointer variable
    // // print the address stored in ptr pointer variable
    // cout << "Address stored in ptr variable: "<< ptr << endl;
    // // access the value at the address stored in pointer
    // cout << "Value of *ptr variable: "<< *ptr << endl;
    // cout << endl;

//// Re-assign value to pointers
    // // Assign a value to where the pointer is pointed to, NOT to the pointer variable
    // *ptr = 99;
    // cout << "Address in ptr: " << ptr << endl;  // Print the address stored in ptr
    // cout << "Value of *ptr: " << *ptr << endl; // Print value pointed to by ptr (99)
    // cout << "Value of a: " << a << endl;   // Print value of a (99)
    //                                       // The value of a changes via pointer
    //
    // cout << "Address of ptr: " << &ptr << endl; // Print the address of pointer variable ptr
    // cout << endl;

//// Uninitialized pointers
    // int * iPtr;
    // //iPtr=&b;
    // *iPtr = 55;
    // cout << *iPtr << endl;

//// Null pointer
    // int *iPtr = NULL;
    // cout << "The value of iPtr: " << iPtr << endl;
    // cout << endl;

//// References &
    // int number = 88;          // Declare an int variable called number
    // int &refNumber = number; // Declare a reference (alias) to the variable number
    //                           // Both refNumber and number refer to the same value
    // cout << "Address of number: " << &number << endl;
    // cout << "Address of refNumber: " << &refNumber << endl;
    // cout << "The value of number: " << number << endl;    // Print value of variable number (88)
    // cout << "The value of refNumber: " << refNumber << endl; // Print value of reference (88)
    // cout << endl;

    // refNumber = 99;            // Re-assign a new value to refNumber
    // cout << "Value of refNumber: " << refNumber << endl;
    // cout << "Value of number: " << number << endl;    // Value of number also changes (99)
    // cout << endl;
    //
    // number = 55;               // Re-assign a new value to number
    // cout << "The value of number: " << number << endl;
    // cout << "The value of refNumber: " << refNumber << endl; // Value of refNumber also changes (55)
    // cout << endl;

//// Re-assign variable to references
    // refNumber = b;        // refNumber is still an alias to number.
    //                       // Assign value of b (5) to refNumber (and number).
    // b = b + 5;
    // cout << "The value of refNumber: " << refNumber << endl;  // 5
    // cout << "The value of number: " << number << endl;     // 5
    // cout << "The value of b: " << b << endl;     // 10
    // cout << endl;


//// Call-by-Value
    // int n1=8;
    // cout << "address of n1 in main(): " << &n1 << endl;
    // int m = square1(n1);
    // cout << "Square of n1: " << m << endl;
    // cout << "No change in n1: " << n1 << endl;
    // cout << endl;

//// Call-by-Reference with Pointer Arguments
    // int n2=8;
    // cout << "address of n2 in main(): " << &n2 << endl;
    // square2(&n2);
    // cout << "Square of n2: " << n2 << endl;
    // cout << "Change reflected in n2: " << n2 << endl;
    // cout << endl;

//// Call-by-Reference with Reference Arguments
    // int n3=8;
    // cout << "address of n3 in main(): " << &n3 << endl;
    // square3(n3);
    // cout << "Square of n3: " << n3 << endl;
    // cout << "Change reflected in n3: " << n3 << endl;
    // cout << endl;


}

//// Call-by-Value
int square1(int n){
    //Address of n in square1() is not the same as n1 in main()
    cout << "address of n1 in square1(): " << &n << "\n";
    // clone modified inside the function
    n *= n;
    return n;
}

//// Call-by-Reference with Pointer Arguments
void square2(int *n){
    //Address of n in square2() is the same as n2 in main()
    cout << "address of n2 in square2(): " << n << "\n";
    // Explicit de-referencing to get the value pointed-to
    *n *= *n;
}

//// Call-by-Reference with Reference Arguments
void square3(int &n){
    //Address of n in square3() is the same as n3 in main()
    cout << "address of n3 in square3(): " << &n << "\n";
    // Implicit de-referencing (without '*')
    n *= n;
}
