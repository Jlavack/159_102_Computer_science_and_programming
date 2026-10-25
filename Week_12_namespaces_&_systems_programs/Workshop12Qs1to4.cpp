#include <iostream>
using namespace std;

//// Workshop 12: Q1
// int age;
// std::string name;
// int main() {
//   std::cout << "Enter your name: ";
//   std::getline(std::cin, name);  //get the line of the input
//   std::cout << "Enter your age: ";
//   std::cin >> age;
//   std::cout << name << " is " << age;
//   std::cout << " years old.\n";
// }

//// Workshop 12: Q2 and Q3
// namespace RGBvalues {
//   int R, G, B;
//   void display();
//   void cout();
// }
//
// using namespace RGBvalues;
//
// int main() {
//   std::cout << "Enter the Red value ";
//   cin >> R;
//   cout << "Enter the Green value ";
//   cin >> G;
//   cout << "Enter the Blue value ";
//   cin >> B;
//   cout << "\nThe RGB values are (" << R << ", ";
//   cout << G << ", " << B << ")\n";
//   RGBvalues::display();
//   RGBvalues::cout();
// }

//// Workshop 12: Q4
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
  int i, yr, total;
  string str;
  i = 0;
  yr = 999;
  while (yr > 0) {
    cout << "Enter year of registration ";
    cin >> yr;
    if (yr > 0) {
      cout << "Enter number plate ";
      cin >> str;
      fleet[i].loaddata(str, yr);
      i++;
    }
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
