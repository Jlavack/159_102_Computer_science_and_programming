#include <iostream>
using namespace std;
void loadalldata();
void removeallmarks();
bool findpath(int here, int last);
class cave_class {
private:
 int numdoors; // number of doors out of the cave
 int door[25]; // hold index number of cave behind the door
 bool marked; // mark a cave when you visit it
public:
 void loaddata(int n, int a, int b, int c, int d, int e);
 int getnumdoors() { return numdoors; }
 int getdoor(int i) { return door[i]; }
 void setmark(bool b) { marked = b; }
 bool getmark() { return marked; }
};
int cave_total; // total number of caves
cave_class cave[500]; // assume a maximum of 500 caves

int main() {
 int first, last;
 bool pathexists;
 loadalldata();
 removeallmarks();
 cout << "Enter the number of the first cave: ";
 cin >> first;
 cout << "Enter the number of the last cave: ";
 cin >> last;
 cout << endl;
 pathexists = findpath(first, last);
 cout << last << endl; // DEBUG cout
 if (pathexists == true) {
 cout << "A path was found from " << first;
 cout << " to " << last << "\n\n";
 } else {
 cout << "There is no path from " << first;
 cout << " to " << last << "\n\n";
 }
}

//------------------------------------------------------------------------
bool findpath(int here, int last) {
 int cavenum, num, i;
 bool success, mark;
 if (here == last) {
 return true; // the base case
 }
 num = cave[here].getnumdoors();//cave of array position 'here'
 mark = cave[here].getmark();
 if (mark == true) {
 return false; // do not visit a marked cave
 }
 cout << here << " -> "; // DEBUG cout
 cave[here].setmark(true); // mark the cave, marked = b
 for (i = 0; i < num; i++) {
   cavenum = cave[here].getdoor(i);
   success = findpath(cavenum, last);
   if (success == true) {
     return true;
 }

 }
 return false;
}
void loadalldata() {
// load the data for all caves - change as needed
// this data is for the example in the notes
// -1 is used to indicate no door
 cave[0].loaddata(3, 4, 3, 2, -1, -1);
 cave[1].loaddata(0, -1, -1, -1, -1, -1);
 cave[2].loaddata(1, 1, -1, -1, -1, -1);
 cave[3].loaddata(2, 0, 2, -1, -1, -1);
 cave[4].loaddata(1, 3, -1, -1, -1, -1);
 cave_total = 5;
}
void removeallmarks() {
// remove the marks from all the caves
 int i;
 for (i = 0; i < cave_total; i++) {
 cave[i].setmark(false);
 }
}
//--------------- methods for the cave_class ------------
void cave_class::loaddata(int n, int a, int b, int c, int d, int e)
{//this is the door data strucure for loadalldata function above. n= the first element in array cave[i].
// WARNING - does not work for more than 5 doors
 numdoors = n;
 door[0] = a;
 door[1] = b;
 door[2] = c;
 door[3] = d;
 door[4] = e;
 //cout << "DEBUG: n:" << n << endl;
}
