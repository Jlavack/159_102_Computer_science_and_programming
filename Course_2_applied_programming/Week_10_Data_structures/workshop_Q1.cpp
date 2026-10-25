#include <iostream>
#include <vector>
using namespace std;

vector<float> data;

void sort(vector<float> & v);
void display(vector<float> & v);


int main() {
  float temp;
  temp = 99.9; // just to start the loop
  while (temp > 0.0) {
    cout << "Enter a positive real number (-1 to stop) ";
    cin >> temp;
    if (temp > 0.0) {
      data.push_back(temp);
    }
  }
sort(data);
display(data);
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
 total = data.size();
 for (i = 0; i < total; i++) {
 cout << data[i] << ", ";
 }
}
