#include <iostream>
using namespace std;

class date_class {
private:
 int day, month, year;
public:
 void setdate(int d, int m, int y);
 int getday() { return day; }
 int getmonth() { return month; }
 int getyear() { return year; }
 void displaydate();
};
date_class *ptr1, *ptr2;
int main() {
 ptr1 = new date_class; // sets aside enough memory for a date
 ptr2 = new date_class;
 ptr1->setdate(14, 7, 1789);
 ptr2->setdate(15, 8, 1947);
 ptr1->displaydate();
 ptr2->displaydate();
}
//--------------- methods for the date_class ------------
void date_class::setdate(int d, int m, int y) {
 day = d;
 month = m;
 year = y;
}
void date_class::displaydate() {
 cout << day << "/" << month << "/" << year << endl;
}
