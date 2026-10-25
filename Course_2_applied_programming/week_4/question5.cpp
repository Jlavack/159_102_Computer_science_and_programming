#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
int Dice1(int first, int last);
int Dice2(int first, int last);
int total;
int count[15];
//-----------------------------------------------------------------
int main() {
 int dice1, dice2, roll, i, low, high;
 srand(683); // the seed – what happens if you change it?
 for (i = 0; i < 15; i++) {
 count[0] = 0;
 }

 low = 1;
 high = 6;
 total = 6000;

 cout << "Generating " << total << " random numbers from 2 to 12\n";
 for (i = 0; i < total; i++) {
   roll = Dice1(low,high) + Dice2(low,high);
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
int Dice1(int first, int last) {
 int diff;
 diff = (last - first) + 1;
 return rand() % diff + first;
}

int Dice2(int first, int last) {
 int diff;
 diff = (last - first) + 1;
 return rand() % diff + first;
}
