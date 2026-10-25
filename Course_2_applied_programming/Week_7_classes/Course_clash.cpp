#include <iostream>
#include <cstdio> // to use getchar
using namespace std;
class session_class {
private:
// a session in the timetable
 string day; // e.g. "Thursday"
 int hour; // 11 = 11am, 13 = 1pm, etc
 string room; // e.g. "SNW300"
public:
 void loaddata();
 bool sametime(session_class other);
};
class course_class {
private:
 int code; // e.g. 159101
 bool core; // true if a core course, otherwise false
 // only one session - maybe there should be more sessions?
 session_class session;
public:
 void loaddata();
 int getcode() { return code; }
 bool sametime(course_class other);
};
class student_class {
private:
 string name; // name of the student
 int num; // number of courses
 course_class courses[30];
public:
 void loadname();
void loadcourses();
 void checkclashes();
};
// assume one student for now - then modify for many students
student_class student;
int main() {
 cout << "Check a student timetable for clashes\n";
 student.loadname();
 student.loadcourses();
 cout << "\nThis student has the following clashes:\n";
 student.checkclashes();
}
//--------------- methods for the session_class ------------
void session_class::loaddata() {
 cout << "Enter the day (e.g. Thursday): ";
 cin >> day;
 cout << "Enter the hour (e.g. 11 = 11am and 13 = 1pm): ";
 cin >> hour;
}
bool session_class::sametime(session_class other) {
 if ((day == other.day) && (hour == other.hour)) {
 return true;
 }
 return false;
}
//--------------- methods for the course_class ------------
void course_class::loaddata() {
 cout << "Enter the course code (e.g. 159101): ";
 cin >> code;
 session.loaddata();
}
bool course_class::sametime(course_class other) {
// return true if both courses have a session at the same time
 if (session.sametime(other.session) == true) {
 return true;
 }
 return false;
}
//--------------- methods for the student_class ------------
void student_class::loadname() {
 cout << "Enter name of student ";
 getline(cin, name);
}
void student_class::loadcourses() {
 int i;
 cout << "How many courses is this student doing? ";
 cin >> num;
 getchar(); // flush the input buffer
 for (i = 0; i < num; i++) {
 courses[i].loaddata();
 }
}
void student_class::checkclashes() {
// check for timetable clashes across the courses
// WARNING - this method could be improved
 int code1, code2, i, k;
 for (i = 0; i < num; i++) {
 for (k = 0; k < num; k++) {
 if (courses[i].sametime(courses[k]) == true) {
 code1 = courses[i].getcode();
 code2 = courses[k].getcode();
 cout << "Clash - " << code1 << " against " << code2 << endl;
 }
 }
 }
}
