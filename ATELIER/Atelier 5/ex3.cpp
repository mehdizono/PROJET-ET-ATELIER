#include <iostream>

class Vect {
protected:
  size_t numElements;
  int *address;

public:
  Vect(size_t size) {
    numElements = size;
    address = new int[size];
  }
  ~Vect() { delete[] address; }
  int &operator[](int index) { return address[index]; }
};

class VectOk : public Vect {
public:
  VectOk(size_t size) : Vect(size) {}

  // Copie profonde.
  VectOk(const VectOk &other) : Vect(other.numElements) {
    for (size_t i = 0; i < numElements; ++i) {
      address[i] = other.address[i];
    }
  }

  VectOk &operator=(const VectOk &other) {
    // Pas de v1 = v1
    if (this != &other) {
      delete[] address;
      numElements = other.numElements;
      address = new int[numElements];
      for (int i = 0; (size_t)i < numElements; ++i) {
        address[i] = other.address[i];
      }
    }
    return *this;
  }

  size_t size() const { return numElements; }
};

void print(const char *name, VectOk &v) {
  std::cout << name << " : ";
  for (int i = 0; (size_t)i < v.size(); ++i) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  VectOk v1(3);
  v1[0] = 10;
  v1[1] = 20;
  v1[2] = 30;

  VectOk v2 = v1;

  VectOk v3(1);
  v3 = v1;

  // Modifier v1 pour prouver que les copies sont indépendantes.
  v1[0] = 999;

  print("v1", v1);
  print("v2", v2);
  print("v3", v3);

  return 0;
}