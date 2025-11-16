#include <iostream>
using namespace std;

class Error {
public:
  int num;
};
class A {
public:
  A(int n) {
    if (n == 1) {
      Error er;
      er.num = 999;
      throw er;
    }
  }
};

int main() {
  void f();
  try {
    f();
  } catch (Error er) {
    // Impossible à atteindre car f() ne génère aucune Error
    cout << "dans main : " << er.num << "\n";
  }
  cout << "suite main\n";
  return 0;
}

void f() {
  try {
    A a(1);
  } catch (Error er) {
    cout << "dans f : " << er.num << "\n";
  }
}

/*
Output :

```
dans f : 999
suite main
```
*/