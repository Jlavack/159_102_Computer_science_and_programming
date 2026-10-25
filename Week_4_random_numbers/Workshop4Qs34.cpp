#include <iostream>
#include <cstdlib> // need this for rand and srand
#include <ctime>
#include <iomanip>
using namespace std;

int RandomInt(int first, int last);
int count[13]={0};// int count[13]={};
//-----------------------------------------------------------------
int main() {
  int roll;
  srand(time(0)); // the seed – what happens if you change it?

  for (int i = 0; i < 6000; i++) {
    // Question 3
    //roll = RandomInt(2, 12);
    //count[roll]++;

    // Question 4
    int die1 = RandomInt(1, 6);
    int die2 = RandomInt(1, 6);
    count[die1+die2]++;

  }

  for(int i=2; i<=12;i++){
    float probability = (float)count[i]/(float)6000;
    cout<<setprecision(2)<<fixed<<"Probability "<<i<<": "<<probability<<"\n";
  }
  //cout << "The event occurred " << count << " times.\n";
}
//-----------------------------------------------------------------
int RandomInt(int first, int last) {
  // returns a random number in the range [first, last]
  int diff;
  diff = (last - first) + 1;
  return rand() % diff + first;
}
