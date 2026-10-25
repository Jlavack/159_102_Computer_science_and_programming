#include <iostream>
namespace RGBvalues {
 int r, g, b;
}

using namespace std;
using namespace RGBvalues;

int main() {
  cout << "Enter a red value: ";
  cin >> r;
  cout << "Enter a green value: ";
  cin >> g;
  cout << "Enter a blue value: ";
  cin >> b;
  cout << "the RGB values are: ";
  std::cout << r << " " << g << " " << b << std::endl;
}
