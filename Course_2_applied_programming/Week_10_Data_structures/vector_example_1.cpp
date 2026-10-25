#include <iostream>
#include <vector>
using namespace std;
vector<int> data;
int main() {
 int i;
 data.push_back(2);
 data.push_back(4);
 data.push_back(6);
 for (i = 0; i < data.size(); i++) {
 cout << data[i] << ", ";
 }
 cout << endl;
}
