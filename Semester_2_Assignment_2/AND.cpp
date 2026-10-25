#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int memory[256];
int reg[16], pc;

main () {
  int command[4] = {10,2,4,7};
  int i, pc=0;

reg[4] = 13;
reg[7] = 10;

  if (command[0] == 10) {
    reg[command[1]] = (reg[command[2]] & reg[command[3]]);
    pc++;
  }

  for (i = 0; i < 16; i++) {
    cout << reg[i] << endl;
  }

  for (i=0; i< 4; i++) {
    cout << uppercase << hex << command[i];
  }
  cout << "    " << "R" << dec << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
  cout << "    PC = " << pc << endl;

}


//--------------------------------
