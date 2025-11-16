#include <iostream>

class Stack {
private:
  int *data;
  int capacity;
  int top; // -1 signifie vide

public:
  explicit Stack(int size = 20) : capacity(size), top(-1) { data = new int[capacity]; }

  ~Stack() { delete[] data; }

  // Désactiver la copie et l'affectation.
  Stack(const Stack &) = delete;
  Stack &operator=(const Stack &) = delete;

  Stack &operator<<(int value) {
    if (top < capacity - 1) {
      data[++top] = value;
    }
    return *this;
  }

  Stack &operator>>(int &value) {
    if (top > -1) {
      value = data[top--];
    }
    return *this;
  }

  int operator++(int) { return (top == capacity - 1) ? 1 : 0; }

  int operator--(int) { return (top == -1) ? 1 : 0; }
};

int main() {
  Stack myStack(3);
  int n1, n2, n3;

  std::cout << "La pile est-elle vide ? " << (myStack-- ? "Oui" : "Non") << std::endl;

  myStack << 10 << 20 << 30;

  std::cout << "La pile est-elle pleine ? " << (myStack++ ? "Oui" : "Non") << std::endl;

  // Empiler dans une pile pleine
  myStack << 40;

  myStack >> n1 >> n2 >> n3;
  std::cout << "Valeurs dépilées : " << n1 << ", " << n2 << ", " << n3 << std::endl;

  std::cout << "Tentative de dépiler d'une pile vide..." << std::endl;
  myStack >> n1;
  std::cout << "La valeur de n1 reste : " << n1 << std::endl;

  // Ça va provoquer une erreur de compilation :
  // Stack anotherStack = myStack;
  // Stack thirdStack(2); thirdStack = myStack;

  return 0;
}