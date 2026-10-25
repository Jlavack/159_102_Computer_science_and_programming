#include <iostream>
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
  int i, total; // items in the array
  int yr, len;
  string platestr, yearstr;
  i = 0;
  // ignore argv[0] - this is the name of the program
  for (int c = 1; c < argc; c = c + 2) {
    platestr = argv[c];
    yearstr = argv[c + 1];
    yr = 0;
    len = yearstr.length();
    for (int j = 0; j < len; j++) {
      yr = yr * 10 + yearstr[j] - 48;
    }
    fleet[i].loaddata(platestr, yr);
    i++;
  }
  total = i;
  cout << "\nVehicle fleet details follow:\n";
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
