#include <iostream>
#include <vector>
using namespace std;

int main() {

  // vector initializationz: initializer list
  vector<int> vector1 = {1, 2, 3, 4, 5};

  // vector initialization: uniform initialization
  vector<int> vector2{6, 7, 8, 9, 10};

  // vector initialization: initilalize a vetcor with same value
  // = vector<int> vector3 = {12, 12, 12, 12, 12};
  vector<int> vector3(5, 12);

  //// using push_back() to add elements to the vector1
  // vector1.push_back(6);
  // vector1.push_back(7);

  //// using insert() to add elements
  // vector1.insert(vector1.begin(),55);
  // vector1.insert(vector1.begin()+3,88);
  // vector1.insert(vector1.end(),100);

  //// using emplace() to add elements
  // vector1.emplace(vector1.begin(),55);
  // vector1.emplace(vector1.begin()+3,88);
  // vector1.emplace(vector1.end(),100);

  //// using pop_back() to remove the last element
  vector1.pop_back();

  cout << "vector1 = ";
  // ranged loop
  for (const int& i : vector1) {
    cout << i << "  ";
  }

  //// using at() to access or change elements
  // vector1.at(3)=20;
  // cout << "\nElement at Index 3: " << vector1.at(3) << endl;

  cout << "\nvector2 = ";
  // ranged loop
  for (const int& i : vector2) {
    cout << i << "  ";
  }

  cout << "\nvector3 = ";
  // ranged loop
  for (int i : vector3) {
    cout << i << "  ";
  }

  cout<<endl;

  return 0;
}
