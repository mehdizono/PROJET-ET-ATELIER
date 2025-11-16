#include <iostream>
using namespace std;

template <class T> class Point {
  T x, y;

public:
  Point(T abs, T ord) {
    x = abs;
    y = ord;
  }
  void display();
  void displayModified();
};
template <class T> void Point<T>::display() { cout << "Coordonnées : " << x << " " << y << "\n"; }
template <class T> void Point<T>::displayModified() {
  cout << "Coordonnées : " << (double)x << " " << (double)y << "\n";
}

int main() {
  Point<char> p(60, 65);
  p.display();         // Output : Coordonnées : < A
  p.displayModified(); // Output : Coordonnées : 60 65
  return 0;
}