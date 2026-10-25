#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int memory[256];
int reg[16], pc;

main () {
  int command[4] = {7,0,15,0};
  int i, pc=0, load;

reg[2] = 2;
reg[15] = 5505;

  if (command[0] == 7) {
    reg[command[2]] = -1*reg[command[2]];
    pc++;
  }

  for (i = 0; i < 16; i++) {
    cout << reg[i] << endl;
  }

  for (i=0; i< 4; i++) {
    cout << uppercase << hex << command[i];
  }
  cout << "    " << "R" << dec << command[2] << " = ";
  cout << setw(4) << setfill('0') << reg[command[2]];
  cout << "    PC = " << pc << endl;

}


//--------------------------------
