#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void converttohex(int memory);
void leadcheck(int lead);

int memory[256];
int reg[16], pc=0;
int command[4];

main () {
  int i, lead;

memory[0] = 4866;
memory[1] = 4355; //4353 test not jump
memory[2] = 25393;
memory[3] = 54019; // if R3 = R0 = 5, jump back to memory2
memory[4] = 57344;

reg[0] = 5;

for (i=0; i<5; i++) {
  cout << uppercase << hex << "Memory [" << i << "] = " << memory[i] << endl;
}
cout << endl;

//loop in here
int j = 5;
  while (pc <= j) {
    converttohex(memory[pc]);//do this for each memory1 and save to command array
    lead = command[0];
    leadcheck(lead);
}

  for (i = 0; i < 16; i++) {
    cout << reg[i] << ", ";
  }
  cout << endl;
}

//--------------------------------

void converttohex(int memory) {
  int remainder, i=0, *ptr;// maybe use five pointers? one for each array
  while (memory != 0) {
    remainder = memory % 16;
    memory = memory / 16;
    ptr = &remainder;
    command[3-i] = *ptr;
    i++;
  }
}

void leadcheck(int lead) {
  int load, i, jumpto;
    if (lead == 1) {
      //Direct Load; 1RXYtest.txt

      if (command[0] == 1) {
        load = 16*command[2] + command[3];
        //cout << "DEBUG: LOADING: " << load << endl;
        reg[command[1]] = load;
        //cout << "DEBUG: Reg "<< memory[1] << ": " << reg[1] << endl;
        pc++;
      }
      for (i=0; i< 4; i++) {
        cout << uppercase << hex << command[i];
      }
      cout << "    " << "R" << dec << command[1] << " = ";
      cout << setw(4) << setfill('0') << load;
      cout << "    PC = " << pc << endl;
//---------------------
    } else if (command[0] == 13) {
      if (reg[command[1]] == reg[0]) {
        int count = pc + 1;
        jumpto = ((16*command[2]) + command[3])-1;
        pc = jumpto;

        for (i=0; i< 4; i++) {
          cout << uppercase << hex << command[i];
        }
        cout << "    " << "R0 = " << "R" << dec << command[1] << "  ";
        cout << "    PC = " << count;
        cout << "  Jumping to Memory[" << pc + 1 << "]" << endl;

      } else if (reg[command[1]] != reg[0]){
        pc++;
        for (i=0; i< 4; i++) {
          cout << uppercase << hex << command[i];
        }
        cout << "    " << "R0 != " << dec << command[1] << "  ";
        cout << "    PC = " << pc << endl;
      }

  } else if (lead == 6) {
      //Add; 6RST
      load = reg[command[2]] + reg[command[3]];
      reg[command[1]] = load;
      pc++;

      for (i=0; i< 4; i++) {
        cout << uppercase << hex << command[i];
      }
      cout << "    " << "R" << dec << command[1] << " = ";
      cout << setw(4) << setfill('0') << reg[command[1]];
      cout << "    PC = " << pc << endl;

  } else if (lead == 14) {
    cout << "Halt" << endl;
    exit(1);
  }
}

/*for (i=0; i< 4; i++) {
  cout << uppercase << hex << command[i];
}
cout << "    " << "R" << dec << command[1] << " = ";
cout << setw(4) << setfill('0') << reg[command[1]];
cout << "    PC = " << pc << endl;*/
