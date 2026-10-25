#include <iostream>
#include <cstdlib> // need this for rand and srand
using namespace std;

int RandomInt(int first, int last);
int  output[7];
//-----------------------------------------------------------------
int main() {
 int result, i, trials, seed, low, high;

 for (i=0; i<7; i++) {
   output[0] = 0;
 }

 cout << "Enter a seed" << endl;
 cin >> seed;
 srand(seed); // the seed – what happens if you change it?
 cout << "Enter trials: " << endl;
 cin >> trials;

 low = 1;
 high = 6;

 for (i = 0; i < trials; i++) {
 result = RandomInt(low, high);
  if ((result >= low && result <= high)) {
    output[result]++;
  }
 }

 for(i=1; i<=6; i++) {
   cout << "Number of rolls of value " << i << " is " << output[i] << endl;
 }
}

//-----------------------------------------------------------------
int RandomInt(int first, int last) {
// returns a random number in the range [first, last]
 int diff;
 diff = (last - first) + 1;
 return rand() % diff + first;
}
