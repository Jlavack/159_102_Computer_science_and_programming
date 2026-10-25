#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

void display(string filename);
int convert_to_dec(string s);
void convert_to_hex(int memory);
void lead_check(int lead);
void direct_load();
void indirect_load();
void load_from_memory();
void store();
void add();
void negate_reg();
void shift_right();
void shift_left();
void and_reg();
void or_reg();
void xor_reg();
void jump();
int loadfile(string filename);

int reg[16], pc = 0, ir, memory[256];
int command[4];
fstream inputfile;          // define a file object
string filename;

int main() {
  int i, j, lead;
  string str[100], line;

  // 1. Enter input file name
  cout << "Enter the FULL name of the file: ";
  cin >> filename;

  //2. load lines into array

  j = loadfile(filename);
//Show memory array make.
  for (i=0; i<5; i++) {
    cout << uppercase << hex << "Memory [" << i << "] = " << memory[i] << endl;
  }
  cout << endl;

/*loop here using the PC.
Show the IR of memory at PC.
Convert the memory at PC to hex, loading it into an array of size 4. This helps
determine which code to execute. Isolate the value in command[0], pointed by the
function convert_to_hex(). Load this into the function to trigger the machine code
and output.*/
    while (pc <= j) {
      ir = memory[pc];
      cout << uppercase << hex << ir;
      convert_to_hex(memory[pc]);//do this for each memory1 and save to command array
      lead = command[0];
      lead_check(lead);
    }
  }

//-----------------------------FUNCTIONS-------------------------------------//

//convert input to decimal to store in memory
int convert_to_dec(string s) {
// convert a string to an integer value
  int i, result = 0, exponent = 1;
  int length = s.length();
  for (i = length-1;  i >= 0; i--) { //working from right to left
    if (s[i] >= '0' && s[i] <= '9') {
      result += (s[i] - 48) * exponent;
      exponent = exponent * 16; //iterating the 16's column
    }
    else if (s[i] >= 'A' && s[i] <= 'F') {
      result += (s[i] - 55) * exponent;
      exponent = exponent * 16;
    }
  }
  return result;
}
//----------------------------------------------------------------------------//
//convert memory[i] to hex string for reading. make this one long funciton to load each command array
void convert_to_hex(int memory) {
  int remainder, i=0, *ptr;// maybe use five pointers? one for each array
  while (memory != 0) {
    remainder = memory % 16;
    memory = memory / 16;
    ptr = &remainder;
    command[3-i] = *ptr;
    i++;
  }
}
//----------------------------------------------------------------------------//
/*check the function leading character and direct to proper function. Could do
it all in this one function, but is hard to read it all and check*/
void lead_check(int lead) {
  if (lead == 1) {
    direct_load();
  } else if (lead == 2) {
    indirect_load();
  } else if (lead == 3) {
    load_from_memory();
  } else if (lead == 4) {
    store();
  } else if (lead == 6) {
    add();
  } else if (lead == 7) {
    negate_reg();
  } else if (lead == 8) {
    shift_right();
  } else if (lead == 9) {
    shift_left();
  } else if (lead == 10) {
    and_reg();
  } else if (lead == 11) {
    or_reg();
  } else if (lead == 12) {
    xor_reg();
  } else if (lead == 13) {
    jump();
  } else if (lead == 14) { //no need to point to another function here. Easy to halt.
    cout << "    Halt" << endl;
    exit(134);
  }
}
//----------------------------------------------------------------------------//
void direct_load () {   //Direct Load; 1RXY
  /*first have to convert the last two array values into one
  decimal number, and load it into the register labelled in command array position 1*/
  reg[command[1]] = 16*command[2] + command[3];
  pc++;

  cout << "    " << "R" << dec << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
  cout << "         PC = " << pc << endl;
}
//----------------------------------------------------------------------------//
void indirect_load() {  //Indirect load; 20RS
  /*Load register R with contents of reigster S*/
  reg[command[2]] = reg[command[3]];
  pc++;

  cout << "    " << "R" << dec << command[2] << " = ";
  cout << setw(4) << setfill('0') << reg[command[3]];
  cout << "         PC = " << pc << endl;
}
//----------------------------------------------------------------------------//
void load_from_memory() {  //load from memory; 3RXY
  /*Convert last two array elements, X and Y to a memory number as decimal.
  Then load this into register R*/
  reg[command[1]] = memory[(16*command[2]) + command[3]];
  pc++;

  cout << "    " << "R" << dec << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
  cout << "         PC = " << pc << endl;
}
//----------------------------------------------------------------------------//
void store() {  //Store; 4RXY
  /*Get the memeory location by converting X and Y positions to decimal. This is
  the array address used in memory. Next store nuber of register R at that memory location*/
  memory[(16*command[2]) + command[3]] = reg[command[1]];
  pc++;

  cout << "    " << "Memory[" << uppercase << hex << memory[(16*command[2]) + command[3]] << "] = ";
  cout << setw(4) << setfill('0') << dec << reg[command[1]];
  cout << "  PC = " << pc << endl;
}
//----------------------------------------------------------------------------//
void add() {  //Add; 6RST
  /*Add registers S and T and store in register R*/
  reg[command[1]] = reg[command[2]] + reg[command[3]];
  pc++;

  cout << "    " << "R" << dec << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
  cout << "         PC = " << pc << endl;
}
//----------------------------------------------------------------------------//
void negate_reg() {   //Negate; 70R0
  /*multiply Register R by -1*/
  reg[command[2]] = -1*reg[command[2]];
  pc++;

  cout << "    " << "R" << dec << command[2] << " = ";
  cout << setw(4) << setfill('0') << reg[command[2]];
  cout << "         PC = " << pc << endl;
}
//----------------------------------------------------------------------------//
void shift_right() {  //Shift right; 8R0X
  /*shift R right by X*/
  reg[command[1]] = (reg[command[1]] >> command[3]);
  pc++;

  cout << "    " << "R" << dec << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
  cout << "         PC = " << pc << endl;
}
//----------------------------------------------------------------------------//
void shift_left() {//Shift left; 9R0X
  /*shift R left by X*/
  reg[command[1]] = (reg[command[1]] << command[3]);
  pc++;

  cout << "    " << "R" << dec << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
  cout << "         PC = " << pc << endl;
}
//----------------------------------------------------------------------------//
void and_reg() {  //AND; ARST
  /*AND registers S and T, then store to register R*/
  reg[command[1]] = (reg[command[2]] & reg[command[3]]);
  pc++;

  cout << "    " << "R" << dec << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
  cout << "         PC = " << pc << endl;
}
//----------------------------------------------------------------------------//
void or_reg() {  //Or; BRST
  /*OR registers S and T, then store to register R*/
  reg[command[1]] = (reg[command[2]] | reg[command[3]]);
  pc++;

  cout << "    " << "R" << dec << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
  cout << "         PC = " << pc << endl;
}
//----------------------------------------------------------------------------//
void xor_reg() {  //XOR; CRST
  /*XOR registers S and T, then store to register R*/
  reg[command[1]] = (reg[command[2]] ^ reg[command[3]]);
  pc++;

  cout << "    " << "R" << dec << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
  cout << "         PC = " << pc << endl;
}
//----------------------------------------------------------------------------//
void jump() { //Jump; DRXY
  /*If register R = R0 then jump. Else iterate the PC. To jump:
  figure out the jump position. Turn X and Y into one value in decimal.
  Load this into the PC, used as the loop variable. New value overwrites the current
  PC. This changes the global variable. First iterate PC, then print the first
  part of the output. Next alter the PC and finish the output telling where the jump lands.*/
  if (reg[command[1]] != reg[0]){
   pc++;
   cout << "    " << "R0 != " << dec << command[1] << "  ";
   cout << "         PC = " << pc << endl;
 } else if (reg[command[1]] == reg[0]) {
    pc++;
    cout << "    " << "R0 = " << "R" << dec << command[1] << "  ";
    cout << "         PC = " << pc;

    pc = ((16*command[2]) + command[3]);
    cout << "  Jumping to Memory[" << pc << "]" << endl;
  }
}
//----------------------------------------------------------------------------//
int loadfile(string filename) {
  string line, str[100];
  int j;
  inputfile.open(filename.c_str(), fstream::in);
  if (inputfile.is_open() == false) {
    cout << "ERROR: not able to open " << filename << endl;
    exit(44);
  } else {
    j=0;
    while (getline(inputfile, line)) {
      str[j] = line;
      memory[j] = convert_to_dec(str[j]);
      j++;
    }
    inputfile.close();
  }
  return j;
}
