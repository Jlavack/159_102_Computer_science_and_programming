#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class machine_code {
private:
  int reg[16], pc = 0, ir, memory[256], command[4], lead, counter;
  string filename;
  fstream inputfile;
public:

  void loadfile(); //using call by reference to iterate counter inside function
  void list_memory();
  void execute();
  void convert_hex_to_array(int memory);
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
};

machine_code load;

int main() {
  //1. Load file and then load lines into array and get the pc counter ceiling.
  load.loadfile();
  //2. Show memory array in hex with 4 digits.
  load.list_memory();
  //3. Execute the machine code.
  load.execute();
}

//-----------------------------FUNCTIONS-------------------------------------//
void machine_code::loadfile() {//iterated counter inside function, else oyutput terminates after one line
  int hexnumber;

  cout << "Enter the FULL name of the file, including file type suffix: ";
  cin >> filename;

  inputfile.open(filename.c_str(), fstream::in);
  while (inputfile.is_open() == false) { //loop until a valid file name is entered.
    inputfile.clear();
    cout << "Error, this file name does not exist. Try again:" << endl;
    cin >> filename;
    inputfile.open(filename.c_str(), fstream::in);
  }
  counter=0;
  while (inputfile >> hex >> hexnumber) {

    memory[counter] = hexnumber;
    counter++;
  }
  inputfile.close();
}
//----------------------------------------------------------------------------//
void machine_code::list_memory () {//counter is stored within the object. no reference call needed here, but this must be called after loadfile funciton, else counter has no value
  int i;

  for (i=0; i<counter; i++) {
    cout << "Memory [" << i << "] = ";
    cout << setw(4) << setfill('0') << uppercase << hex << memory[i] << endl;
  }
  cout << endl;
  cout << "Note: all output is in hexadecimal" << endl;
}
//----------------------------------------------------------------------------//
void machine_code::execute() {
  /*loop here using the PC.
  Show the IR of memory at PC.
  Convert the memory at PC to hex, loading it into an array of size 4. This helps
  determine which code to execute. Isolate the value in command[0], pointed by the
  function convert_to_hex(). Load this into the function to trigger the machine code
  and output.*/
  while (pc <= counter) {
    ir = memory[pc];
    cout << uppercase << hex << ir << "    ";
    convert_hex_to_array(memory[pc]);//do this for each memory1 and save to command array
    lead = command[0];
    lead_check(lead);
    cout << endl;
  }
}
//----------------------------------------------------------------------------//
//convert memory[i] to hex  for reading.
void machine_code::convert_hex_to_array(int memory) {
  int remainder, i=0;//
  while (memory != 0) {
    remainder = memory % 16;
    memory = memory / 16;
    command[3-i] = remainder;
    i++;
  }//could also use a mask here. Since the last two digits are not always used as a single hex number, it is more useful to have the array
}
//----------------------------------------------------------------------------//
/*check the function leading character and direct to proper function. Could do
it all in this one function, but is hard to read it all and check*/
void machine_code::lead_check(int lead) {
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
    cout << "Halt" << endl << endl;
    exit(135);
  }
}
//----------------------------------------------------------------------------//
void machine_code::direct_load () {   //Direct Load; 1RXY
  /*first have to convert the last two array values into one
  decimal number, and load it into the register labelled in command array position 1*/
  reg[command[1]] = 16*command[2] + command[3];
  pc++;
  cout << "PC = " << setw(3) << setfill('0') << dec << pc << "    ";
  cout << "R" << hex << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
}
//----------------------------------------------------------------------------//
void machine_code::indirect_load() {  //Indirect load; 20RS
  /*Load register R with contents of reigster S*/
  reg[command[2]] = reg[command[3]];
  pc++;
  cout << "PC = " << setw(3) << setfill('0') << dec << pc << "    ";
  cout << "R" << hex << command[2] << " = ";
  cout << setw(4) << setfill('0') << reg[command[3]];
}
//----------------------------------------------------------------------------//
void machine_code::load_from_memory() {  //load from memory; 3RXY
  /*Convert last two array elements, X and Y to a memory number as decimal.
  Then load this into register R*/
  reg[command[1]] = memory[(16*command[2]) + command[3]];
  pc++;
  cout << "PC = " << setw(3) << setfill('0') << dec << pc << "    ";
  cout << "R" << hex << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
}
//----------------------------------------------------------------------------//
void machine_code::store() {  //Store; 4RXY
  /*Get the memory location by converting X and Y positions to a hex integer. This is
  the array address used in memory. Next store nuber of register R at that memory location*/
  memory[(16*command[2]) + command[3]] = reg[command[1]];
  pc++;
  cout << "PC = " << setw(3) << setfill('0') << dec << pc << "    ";
  cout << "Memory["  << uppercase << hex << (16*command[2]) + command[3] << "] = ";
  cout << setw(4) << setfill('0') << hex << reg[command[1]];
}
//----------------------------------------------------------------------------//
void machine_code::add() {  //Add; 6RST
  /*Add registers S and T and store in register R*/
  reg[command[1]] = reg[command[2]] + reg[command[3]];
  pc++;
  cout << "PC = " << setw(3) << setfill('0') << dec << pc << "    ";
  cout << "R" << hex << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
}
//----------------------------------------------------------------------------//
void machine_code::negate_reg() {   //Negate; 70R0
  /*multiply Register R by -1*/
  reg[command[2]] = -1*reg[command[2]];
  pc++;
  cout << "PC = " << setw(3) << setfill('0') << dec << pc << "    ";
  cout << "R" << hex << command[2] << " = ";
  cout << setw(4) << setfill('0') << (reg[command[2]]); //displays in hex, very long number...
}
//----------------------------------------------------------------------------//
void machine_code::shift_right() {  //Shift right; 8R0X
  /*shift R right by X*/
  reg[command[1]] = (reg[command[1]] >> command[3]);
  pc++;
  cout << "PC = " << setw(3) << setfill('0') << dec << pc << "    ";
  cout << "R" << hex << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
}
//----------------------------------------------------------------------------//
void machine_code::shift_left() {//Shift left; 9R0X
  /*shift R left by X*/
  reg[command[1]] = (reg[command[1]] << command[3]);
  pc++;
  cout << "PC = " << setw(3) << setfill('0') << dec << pc << "    ";
  cout << "R" << hex << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
}
//----------------------------------------------------------------------------//
void machine_code::and_reg() {  //AND; ARST
  /*AND registers S and T, then store to register R*/
  reg[command[1]] = (reg[command[2]] & reg[command[3]]);
  pc++;
  cout << "PC = " << setw(3) << setfill('0') << dec << pc << "    ";
  cout << "R" << hex << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
}
//----------------------------------------------------------------------------//
void machine_code::or_reg() {  //Or; BRST
  /*OR registers S and T, then store to register R*/
  reg[command[1]] = (reg[command[2]] | reg[command[3]]);
  pc++;
  cout << "PC = " << setw(3) << setfill('0') << dec << pc << "    ";
  cout << "R" << hex << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
}
//----------------------------------------------------------------------------//
void machine_code::xor_reg() {  //XOR; CRST
  /*XOR registers S and T, then store to register R*/
  reg[command[1]] = (reg[command[2]] ^ reg[command[3]]);
  pc++;
  cout << "PC = " << setw(3) << setfill('0') << dec << pc << "    ";
  cout << "R" << hex << command[1] << " = ";
  cout << setw(4) << setfill('0') << reg[command[1]];
}
//----------------------------------------------------------------------------//
void machine_code::jump() { //Jump; DRXY
  /*If register R = R0 then jump. Else iterate the PC. To jump:
  figure out the jump position. Turn X and Y into one value in decimal.
  Load this into the PC, used as the loop variable. New value overwrites the current
  PC. This changes the global variable. First iterate PC, then print the first
  part of the output. Next alter the PC and finish the output telling where the jump lands.
  Note teh PC and the memory location are out of step by 1, as memory is zero inclusive while PC is not.*/
  if (reg[command[1]] != reg[0]){
   pc++;
   cout << "PC = " << setw(3) << setfill('0') << dec << pc << "    ";
   cout << "R0 = " << reg[0] <<" != R" << hex << command[1] << " = " << reg[command[1]];
 } else if (reg[command[1]] == reg[0]) {
    pc++; //iterate
    cout << "PC = " << setw(3) << setfill('0') << dec << pc << "    ";
    pc = ((16*command[2]) + command[3]); //reset to new value
    cout << "R0 = R" << hex << command[1] << " = " << reg[0];
    cout << " jump to memory[" << (16*command[2]) + command[3] << "]";
  }
}
//----------------------------------------------------------------------------//
