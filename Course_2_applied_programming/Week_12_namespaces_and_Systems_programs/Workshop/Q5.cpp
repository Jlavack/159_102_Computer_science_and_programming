#include <iostream>
using namespace std;

class vehicle_class {
private:
 string plate; // e.g. "ABC123"
 int year; // e.g. 2004
public:
 void loaddata(string p, int y);
 void display();
};

vehicle_class fleet[100];

int main(int argc, char* argv[]) {
  int i, total; //items in the array;
  int c, count; //argument counting
  int j; //index for inside year string
  int yr, len;
  string plate, year;

  count = argc - 1; //number arguments entered
  i = 0; //initialise i index for items in array
 // ignore argv[0] - this is the name of the program
  for (c = 1; c < count; c = c + 2) {
    plate = argv[c];
    year = argv[c + 1];
    yr = 0;
    len = year.length();
    for (j =0; j < len; j++) {
      yr = yr * 10 + year[j] - 48; //convert to integer
    }
    fleet[i].loaddata(plate, yr);
    i++;
  }
  total = i;
  cout << "Vehicle fleet details are as follows: ";
  for (i = 0; i < total; i++) {
    fleet[i].display();
    }
  }

  //-------------- methods for the vehicle_class ------------
  void vehicle_class::loaddata(string p, int y) {
   plate = p;
   year = y;
  }
  void vehicle_class::display() {
   cout << "Number plate " << plate;
   cout << " First registered in " << year << endl;
  }
