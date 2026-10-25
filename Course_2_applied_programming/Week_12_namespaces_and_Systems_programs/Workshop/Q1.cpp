#include <iostream>
namespace mynamespace {
 int age;
 std::string name;
}

using namespace mynamespace;

int main() {
  std::cout << "Ënter an age and name: ";
  std::cin >> mynamespace::age;
  std::cin >> mynamespace::name;

 std::cout << mynamespace::name << " is " << mynamespace::age << std::endl;
}
