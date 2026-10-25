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

// int main(int argc, char* argv[]) {
int main() {
  int i, year, total;
  string plate;

  i=0;
  year = 999;

  while (year > 0) {
    cout << "Enter a registration year for the vehicle, -1 to stop: ";
    cin >> year;
    if (year > 0) {
      cout << "Enter a licence plate number: ";
      cin >> plate;
      fleet[i].loaddata(plate, year);
      i++;
    }
  }
  total = i;

  cout << "Vehicle fleet details are: " << endl;
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
