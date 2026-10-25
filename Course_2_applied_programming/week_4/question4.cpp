#include <iostream>
#include <cstdlib>
using namespace std;
int RandomInt(int first, int last);
int total;
int count[15];
//-----------------------------------------------------------------
int main() {
 int roll, i;
 srand(683); // the seed – what happens if you change it?
 for (i = 0; i < 15; i++) {
 count[0] = 0;
 }
 total = 6000;
 cout << "Generating " << total << " random numbers from 2 to 12\n";
 for (i = 0; i < total; i++) {
 roll = RandomInt(2, 12);
 if ((roll >= 2) && (roll <= 12)) {
 count[roll]++;
 } else {
 cout << "Illegal roll of " << roll << endl;
 }
 }
 cout << "\nResults:\n";
 for (i = 2; i <= 12; i++) {
 cout << "Rolled " << i << ": " << count[i] << " times.\n";
 }
 cout << endl;
}
//-----------------------------------------------------------------
int RandomInt(int first, int last) {
// returns a random number in the range [first, last]
 int diff;
 diff = (last - first) + 1;
 return rand() % diff + first;
}
