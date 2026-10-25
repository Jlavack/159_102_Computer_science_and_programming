#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<float> numbers;
void sort(vector<float> & v);
void display(vector<float> & v);

int main() {
//// asking users to input values, then put them in the vector
  // float temp;
  // temp = 99.9; // just to start the loop
  // while (temp > 0.0) {
  //   cout << "Enter a positive real number (-1 to stop) ";
  //   cin >> temp;
  //   if (temp > 0.0) {
  //     numbers.push_back(temp);
  //   }
  // }

//// sort vector
  numbers = {20,2,10,5,7};
  //// build our own sort function, using bubble sort algorithm
  sort(numbers);

  //// using sort() provided by c++ to sort the vector in ascending order,
  //// the third parameter, comp, as less<float>() function by default
  //sort(numbers.begin(),numbers.end());

  //// using sort() provided by c++ to sort the vector in descending order
  //// the third parameter, comp, as greater<float>() function
  //sort(numbers.begin(),numbers.end(),greater<float>());

  display(numbers);

//// Using sort() to sort array
  // int demo[5] = {44, 22, 55, 33, 66};
  // int len = sizeof(demo)/sizeof(demo[0]);
  // //sort(demo, demo + len); //Sorting demo array in ascending order
  // sort(demo, demo + len, greater<int>()); //Sorting demo array in descending order
  // cout<<"\n\nAfter sorting array : ";
  // for(int i=0; i<len; i++){
  //     cout << " " << demo[i];
  // }
  // cout << endl;
}

void sort(vector<float> & v) {
  int total, pass, i;
  float temp;
  total = v.size();
  for (pass = 0; pass < total; pass++) {
    for (i = 0; i < total - 1; i++) {
      if (v[i] > v[i+1]) {
        temp = v[i];
        v[i] = v[i+1];
        v[i+1] = temp;
      }
    }
  }
}

void display(vector<float> & v) {
  int total, i;
  total = numbers.size();
  for (i = 0; i < total; i++) {
    cout << numbers[i] << ", ";
  }
  cout << endl;
}
