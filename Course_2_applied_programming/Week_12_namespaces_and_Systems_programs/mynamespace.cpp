#include <iostream>
using namespace std;
namespace mynamespace {
 int value;
}
int value;
int main() {
 value = 150;
 mynamespace::value = 202;
 cout << "The global value is " << value << endl;
 cout << "The value in the namespace is ";
 cout << mynamespace::value << endl;
}
