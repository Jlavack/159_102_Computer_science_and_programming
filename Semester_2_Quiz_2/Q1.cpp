#include <iostream>
using namespace std;

void adding(float *v1, float *v2);

int main() {
  float r, s;
  cout << "Enter the first value ";
  cin >> r;
  cout << "Enter the second value ";
  cin >> s;
  adding(&r, &s);
  cout << "The results are " << r;
  cout << " and " << s << endl;
}

void adding(float *v1, float *v2) {
  *v1 = *v1 + 2;
  *v2 = *v2 + 3;
}
