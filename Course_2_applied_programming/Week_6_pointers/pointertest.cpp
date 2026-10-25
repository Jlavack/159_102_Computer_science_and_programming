#include <iostream>
using namespace std;

void point(int mem);

int numbers[4];


int main() {
  int i, j;
  int memory[2] = {4354, 16639};

  for (j=0; j<2; j++) {
    point(memory[j]);
    for (i=0; i<4; i++) {
      cout << numbers[i];
    }
  cout << endl;
  }
  cout << numbers[2] << endl;

}

void point(int mem) {
  int temp, i=0, *ptr;
  while( mem != 0) {
    temp = mem % 16;
    mem = mem / 16;
    ptr = &temp;
    numbers[3-i] = *ptr;
    i++;
  }

}
