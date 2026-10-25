#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class shop_class{
private:
  string name;
  float price;
  int stock;
public:
  void load_data();
  void display_data();
};

shop_class items[1000];

int main() {
  int i;
  for (i=0; i<4; i++) {
    items[i].load_data();
  }

  for (i=0; i<4; i++) {
    items[i].display_data();
  }
}

//-------------methods----------------
void shop_class::load_data() {
  //enter name of item
  //enter price of item
  //enter stock
  cout << "Enter name of item: ";
  getline(cin, name);
  cout << "Enter the price of item: ";
  cin >> price;
  cout << "Enter the stock level of item: ";
  cin >> stock;
  getchar();
}

void shop_class::display_data() {
  cout << "item: " << name << "   $" << price;
  cout << "   stock level: " << stock << endl;
}
