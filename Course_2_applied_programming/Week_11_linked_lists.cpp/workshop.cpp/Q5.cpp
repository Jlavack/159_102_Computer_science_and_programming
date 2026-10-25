/* Create a class to hold data for a domestic flight. The class must store the following information:
the flight number, e.g. NZ161 (string)
the departure place, e.g. Auckland (string)
the arrival place, e.g. Wellington (string)
the travel time in minutes, e.g. 85 (positive whole number)
Create some useful methods, for example loaddata and display.
Using the <list> library, create a list where each node in the list will be an object of the flight
class described above.
 */

 #include <iostream>
 #include <list>
 #include <cstdio>
 #include <string>
 using namespace std;

 class Flight {
 private:
   int number, time;
   string departs, arrives;
   Flight *next;
 public:
  void loaddata();
  void display();
  int getnumber() { return number; }
 };

void displaylist(list<Flight> l);
list <Flight> mylist;

int main() {
   int i, searchvalue;
   Flight temp;
   list<Flight>::iterator ptr;

   for (i=0; i < 3; i++) {
     temp.loaddata();
     mylist.push_back(temp);
   }

//   displaylist(mylist);

  cout << "Which value should be removed? \n";
  cin >> searchvalue;

//removing the value:
  for (ptr = mylist.begin(); ptr != mylist.end(); ptr++) {
  //  ptr->getnumber();
    if(ptr->getnumber() == searchvalue) {
      cout << "DEBUG: found it" << endl;
      mylist.erase(ptr);
      //ptr--;
      break;
    }
  }
  displaylist(mylist);
}

//------------------------------FUNCCTIONS------------------------------------//

 void displaylist(list<Flight> l) {//can use methods of Flight because list used Flight object
   list<Flight>::iterator ptr;
   for (ptr = l.begin(); ptr != l.end(); ptr++) {
     ptr->display();
   }
   cout << endl;
 }

 //--------------methods for Flight-------------------------------------------//
void Flight::loaddata() {
  cout << "Enter flight number: ";
  cin >> number;
  getchar();
  cout << "Enter port of departure: ";
  getline(cin, departs);
  cout << "Enter port of arrival: ";
  getline (cin, arrives);
  cout << "Enter flight time: ";
  cin >> time;
  getchar();//flush buffer
}

void Flight::display() {
  cout << "Information about flight: " << number << endl;
  cout << "Departs from " << departs << endl;
  cout << "Arrives at " << arrives << endl;
  cout << "Flight time: " << time << endl;
}
