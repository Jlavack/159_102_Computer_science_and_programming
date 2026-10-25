#include <iostream>
using namespace std;
class tiny_class {
private:
 bool small;
public:
 void setsmall(bool b) { small = b; }
};
tiny_class m;
tiny_class *r;
int main(){
 r = &m;
 r = new tiny_class;
 cout << "Address of m is " << &m << endl;
 cout << "Address stored in r is " << r << endl;
}
