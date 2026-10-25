#include <iostream>
#include <bitset>
using namespace std;

int main() {

//// Workshop 3, Q5
    // unsigned int m = 12;
    // m = m >> 3;
    // cout<< "m = " << m <<endl;
    //
    // unsigned int n = 1;
    // n = n << 3;
    // cout << "n = " << n << endl;

//// Workshop 3, Q6
    // //char c = 0xA4;
    // unsigned char c = 0xA4;
    // c = c >> 2;
    // cout << "c is " << (int)c <<endl;

//// Workshop 3, Q7. c)
    // unsigned char c = 0xA4;
    // unsigned char mask = 0x07;
    // c = c & mask;
    // cout << "c is " << (int)c <<endl;
    //
    // //cout << "c after mask: " << bitset<8>(c) <<endl;

//// Workshop 3, Q7. d)
    unsigned char c = 0xA4;
    unsigned char mask = 0xE0;
    c = c & mask;
    cout << "c is " << (int)c <<endl;

    // use bitset to display binary nubmer
    cout << "c after mask: " << bitset<8>(c) <<endl;

    // right shift 5 to get the top three bits
    c = c >> 5;
    cout << "c after shift: " << bitset<8>(c) <<endl;


}
