//John Lavack 20001249.
//159.102 assignment 1
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool emptycheck(string s);
bool binarycheck(string s);
bool validatebinary(string s);
bool validatenumber(string s);
int converttoint(string s);
bool validatedecimal(int decimal);
void binarytodecimal(string s);
void decimaltobinary(int decimal);

int main () {
  string input;
  int decimal, length;
  bool pass = false, empty, binary = false, numcheck = false;
  cout << "Enter a number: ";
  getline(cin, input);
  length=input.length();

  while (pass == false) { //while loop to allow mutliple attempts.
     if ((input[0] == '0') && (length == 1)) { //binary must have laeding zero. Decimal must not. 0 input is technically both and neither. Assume correct and provide outcome for both number systems
      cout << "The result from converting 0 from decimal to binary or from binary to decimal is: 0" << endl;
      pass = true;
      exit(1); //exit neatly, without a lagging enter.
    }
    empty = emptycheck(input); //first check if empty input
    if (empty == true) {
      pass = false; //exit loop if empty
    }
    binary = binarycheck(input); //next check if binary
    if ((binary == true) && (empty == false)) {
      pass = validatebinary(input); //validate binary input with only 0, 1 and no more than 9 binary digits
      if (pass == true) {
        binarytodecimal(input); //if input is binary, then covert to decimal
      }
    } else if ((binary == false) && (empty == false)) { //if not binary then decimal input
      numcheck = validatenumber(input); //check no letters or characters
      if (numcheck == true) { //if number then convert to integer
        decimal = converttoint(input);
        pass = validatedecimal(decimal); //check integer in range
        if (pass == true) {
          decimaltobinary(decimal); //if decimal is made of integers and in range, convert to binary
        }
      }
    }
    getline(cin,input); //if fail all validations loop.
  }
}

//------------------functions------------------------------//
//----Check for empty Input
/*check first if input is empty. Otherwise read in as 0. Give chances to correct
input using while loop*/
bool emptycheck(string s) {
 bool emptycheck;
 if (s.empty()) {
   cout << "This not a valid number." << endl << "Enter a number: ";
   emptycheck = true;
 } else {
   emptycheck = false;
 }
 return emptycheck;
}

//----Check input type
bool binarycheck(string s) { //binary check looks for a leading zero. If none, assumes decimal.
  bool binary = false;
  if (s[0] == '0') {
    binary = true;
  } else {
    binary = false;
  }
  return binary;
}

//----validate input
/*could have also put a check for input of 0 only here. Wanted to keep this function concise*/
bool validatebinary(string s) {
  int i;
  bool pass = true;
  int length = s.length();
  if (length > 9) {
    cout << "This binary number has more than 9 binary digits." << endl << "Enter a number: ";
    pass = false;
  } else if (length < 9) {
    for (i = 0; i < length; i++) {
      if ((s[i] != '0') && (s[i] != '1')) {
        cout << "This is not a valid binary number." << endl << "Enter a number: ";
        pass = false;
        break;
      }
    }
  }
  return pass;
}

//----Validate decimal is a number
/*using input as a string, check for any characters in array and reject if true.
//using negative logic here. Assuming input is valid and rejecting if not valid. This to make it
easier to work with the return of this function. */
bool validatenumber(string s) {
  bool numcheck = true;
  int length = s.length(), i;
  for (i = 0; i < length; i++) {
    if (s[0] == '-') { //tehcnically not needed, as negatives will trigger the second error without this. For specificity included, as user will think negatives are valid numbers.
      cout << "This decimal number is outside the range 0 to 255." << endl << "Enter a number: ";
      numcheck = false;
      break;
    } else if (s[i] < 48 || s[i] > 57) {
      cout << "This is not a valid number." << endl << "Enter a number: ";
      numcheck = false;
      break; //else error prints for each character in input
    }
  }
  return numcheck;
}

//----Change to integer
/*For straighforwardness, this happens before validating range. Otherwise it
beocmes complicated with many if statements on each input*/
int converttoint(string s) {
  int i, total, result;
  result = 0;
  total=s.length();
  for (i = 0; i < total; i++) {
    result = result * 10 + s[i] - 48;
  }
  return result;
}

//----Validate decimal
/*Only checks range.*/
bool validatedecimal(int decimal) {
  bool pass = false;
  if (decimal < 0 || decimal > 255) {
    cout << "This decimal number is outside the range 0 to 255." << endl << "Enter a number: ";
  } else {
    pass = true;
  }
  return pass;
}

//----Change binary to decimal
/*using the binary conversion by exponents of 2*/
void binarytodecimal(string s) {
  string trimmed;
  int i, j = 0, result;
  int length = s.length(); // find length of input
  int exponents[length]; //set up an array of exponents
  for (i = 0; i < length; i++) {
    exponents[i] = i; //this will be 0-8 ensured by i < length
  }
  for (i = 0; i < length; i++) { //there are 9 characters. Trimm off leading zero.
    trimmed[i] = s[i+1]; //trimmed array will have second character aligned with 0 in exponent array.
  }
  result = 0; //set this up to store the summation
  for (i = length; i > -1; i--) { //need to flip the input for the first element in trimmed[] to align with highest exponent
    if (trimmed[i] == '1') {
      result = result + pow(2,exponents[j]);
      j++;
    } else if (trimmed[i] == '0') {
      result = result;
      j++;
    } //only adds to sum if element is 1. Else the result is always too large.
  }
  cout << "Converting binary to decimal. The result is: " << result << endl;
  exit(1); //neatly exits without needing ot press enter once more.
}

  //---- Change decimal to binary
  /*Follows the algortihm. Find remainder of input, then rest input as
  the input halved. Input here has been changed to a decimal. This will only ever
  result in one or 0. These are stored in an array. Loop this for until we hit the
  bit limit of 8. For an input > 255, increase array size.*/
  void decimaltobinary(int decimal) {
    int binary[8], i;
    for (i = 0; i < 8; i++) {
      binary[i] = 0;
    }
    for (i = 0; decimal > 0; i++) {
      binary[i] = decimal % 2;
      decimal = decimal / 2;
    }
    /*now print. Given the 8 bit condition, it was easier to print the output this way,
    rather than inserting a space every 4 characters by calling another function. The first
    step of which would be to reverse the array. Here it was more straightforward to count
    backwards from 8 and print a space*/
    cout << "Converting decimal to binary. The result is ";
    for (i = 7; i >= 4; i--) {
      cout << binary[i];
    }
    cout << " ";
    for (i = 3; i >= 0; i--) {
      cout << binary[i];
    }
    cout << endl;
    exit(1); // neat exit without additional enter stroke
  }
