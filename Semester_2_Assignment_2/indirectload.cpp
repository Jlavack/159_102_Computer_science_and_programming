#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;



int reg[16], pc;

main () {
  int command[4] = {2,0,4,3};
  int i, pc=0, load;

reg[3] = 9;

  if (command[0] == 1) {
    load = 16*command[2] + command[3];
    //cout << "DEBUG: LOADING: " << load << endl;
    reg[command[1]] = load;
    //cout << "DEBUG: Reg "<< memory[1] << ": " << reg[1] << endl;
    pc++;
  } else if (command[0] == 2) {
    reg[command[2]] = reg[command[3]];
    pc++;
  }


  for (i = 0; i < 16; i++) {
    cout << reg[i] << endl;
  }

  for (i=0; i< 4; i++) {
    cout << command[i];
  }
  cout << "    " << "R" << command[2] << " = ";
  cout << setw(4) << setfill('0') << reg[command[3]];
  cout << "    PC = " << pc << endl;

}


//--------------------------------
