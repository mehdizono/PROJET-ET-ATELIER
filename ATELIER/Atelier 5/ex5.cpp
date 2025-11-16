#include <iostream>

template <typename T> T square(T value) { return value * value; }

int main() {
  int intNumber = 5;
  std::cout << "Le carré de " << intNumber << " est " << square(intNumber) << std::endl;

  double doubleNumber = 4.2;
  std::cout << "Le carré de " << doubleNumber << " est " << square(doubleNumber) << std::endl;

  return 0;
}