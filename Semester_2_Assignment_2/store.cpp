#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int memory[256];
int reg[16], pc;

main () {
  int command[4] = {4,2,15,15};
  int i, pc=0, location;

reg[2] = 99;
memory[50] = 11;

  if (command[0] == 4) {
    location = (16*command[2]) + command[3];
    memory[location] = reg[command[1]];
    pc++;
  }

  for (i = 0; i < 16; i++) {
    cout << reg[i] << endl;
  }

  for (i=0; i< 4; i++) {
    cout << command[i];
  }
  cout << "    " << "Memory[" << uppercase << hex << location << "] = ";
  cout << setw(4) << setfill('0') << dec << reg[command[1]];
  cout << "    PC = " << pc << endl;

}


//--------------------------------
