#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int memory[256];
int reg[16], pc;

main () {
  int command[4] = {3,2,3,2};
  int i, pc=0;

reg[3] = 9;
memory[50] = 11;

  if (command[0] == 3) {
    reg[command[1]] = memory[(16*command[2]) + command[3]];
    //cout << "DEBUG: Reg "<< memory[1] << ": " << reg[1] << endl;
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
