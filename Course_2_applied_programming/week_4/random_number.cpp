#include <iostream>
#include <cstdlib> // need this for rand and srand
using namespace std;
int RandomInt(int first, int last);
//-----------------------------------------------------------------
int main() {
 int chance, count, i, x, low, high, target;
 cout << "Enter a seed" << endl;
 cin >> x;
 cout << "Enter range:" << endl;
 cout << "Low end: ";
 cin >> low;
 cout << "High end: " ;
 cin >> high;
 cout << "Enter a target value: ";
 cin >> target;

 srand(x); // the seed – what happens if you change it?

 count = 0;
 for (i = 0; i < 1000; i++) {
 chance = RandomInt(low, high);
 if (chance <= target) { // chance of event occuring
 count++;
}
 }
 cout << "This event has a " << (count/10) << "% chance of occurring.\n\n";
 cout << "The event occurred " << count << " times.\n";
}
//-----------------------------------------------------------------
int RandomInt(int first, int last) {
// returns a random number in the range [first, last]
 int diff;
 diff = (last - first) + 1;
 return rand() % diff + first;
}
