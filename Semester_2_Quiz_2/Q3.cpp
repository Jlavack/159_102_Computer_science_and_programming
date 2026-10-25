#include <iostream>
#include <vector>
using namespace std;

class student_class {
private:
  int id;
  string degree;  // BA, BCom, BSc
public:
  void loaddata();
  void display();
  bool is_BSc();
};

student_class *student;
vector<student_class> data;

void display_vector();

int main() {
  int i;

  cout << "Enter three student IDs and degrees: " << endl;
  for (i=0; i<3; i++) {
    cout << "Student " << i+1 << ": " << endl;
    student = new student_class;
    student->loaddata();
    data.push_back(*student);
}
display_vector();

}


void display_vector() {
  int i=1;
  vector<student_class>::iterator it;
  cout << "displaying the student completing a BSc" << endl;
  cout << "------------------------------------------------------------------" << endl;
    for (it = data.begin(); it != data.end(); it++) {
      if (it->is_BSc() == true) {
        it -> display();
        cout << endl;
      }
      i++;
    }
  }


//--------methods for student_class-----------------------------------------//

void student_class::loaddata() {
  cout << "Enter ID of student: ";
  cin >> id;
  getchar();
  cout << "Now enter the degree, either BA, BCom or BSc: ";
  getline(cin, degree);
}

void student_class::display() {
  cout << "Student with ID: " << id << " is completing a " << degree << endl;
}

bool student_class::is_BSc() {
  if (degree == "BSc") {
    return true;
  }
  return false;
}
