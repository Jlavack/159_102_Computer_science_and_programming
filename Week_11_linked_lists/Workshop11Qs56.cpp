#include <iostream>
#include <list>
using namespace std;

class flight_class {
  private:
    string fltnum, departure, arrival;
    int minutes;
  public:
    void loaddata();
    void display();
};

list<flight_class> mylist;

int main(){
  flight_class temp;
  int value;
  value = 999; // ensure that value > zero
  while (value >= 0) {
    cout << "Enter an integer value (-1 to stop) ";
    cin >> value;
    getchar();
    if (value >= 0) {
      temp.loaddata();
      mylist.push_back(temp);
    }
  }
  // display all flights information
  list<flight_class>::iterator ptr;
  for (ptr = mylist.begin(); ptr != mylist.end(); ptr++) {
    ptr->display();
  }
  cout << endl;
}

//-------------- methods for the flight_class ------------
void flight_class::loaddata() {
  cout << "Enter the flight number, e.g. NZ161 ";
  getline(cin, fltnum);
  cout << "Enter the departure place ";
  getline(cin, departure);
  cout << "Enter the arrival place ";
  getline(cin, arrival);
  cout << "Enter the travel time in minutes ";
  cin >> minutes;
  getchar(); // flush the input buffer
}

void flight_class::display() {
  cout << "Information about flight " << fltnum << endl;
  cout << "Departs from " << departure << endl;
  cout << "Arrives at " << arrival << endl;
  cout << "Travel time is " << minutes << " minutes.\n";
}
