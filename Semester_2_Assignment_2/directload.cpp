#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;



int reg[16], pc;

main () {
  int command[4] = {1,2,1,3};
  int i, pc=0, load;

  if (command[0] == 1) {
    load = 16*command[2] + command[3];
    //cout << "DEBUG: LOADING: " << load << endl;
    reg[command[1]] = load;
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
  cout << setw(4) << setfill('0') << load;
  cout << "    PC = " << pc << endl;

}


//--------------------------------
