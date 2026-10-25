#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int memory[256];
int reg[16], pc;

main () {
  int command[4] = {6,15,3,2};
  int i, pc=0, load;

reg[2] = 2;
reg[3] = 5505;

  if (command[0] == 6) {
    load = reg[command[2]] + reg[command[3]];
    reg[command[1]] = load;
    pc++;
  }

  for (i = 0; i < 16; i++) {
    cout << reg[i] << endl;
  }

  for (i=0; i< 4; i++) {
    cout << command[i];
  }
  cout << "    " << "R" << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
  cout << "    PC = " << pc << endl;

}


//--------------------------------
