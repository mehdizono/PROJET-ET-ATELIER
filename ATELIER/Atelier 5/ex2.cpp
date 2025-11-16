#include <iostream>

using namespace std;

class Test {
public:
  static int numberArray[];
  static const int arraySize;

public:
  static int performDivision(int index, int divisor) {
    // La division par zéro.
    if (divisor == 0) {
      throw "Error: Division by zero is not allowed.";
    }

    // Bounds check.
    if (index < 0 || index >= arraySize) {
      throw "Error: Index is out of bounds.";
    }

    return numberArray[index] / divisor;
  }
};

int Test::numberArray[] = {17, 12, 15, 38, 29, 157, 89, -22, 0, 5};

const int Test::arraySize = sizeof(Test::numberArray) / sizeof(Test::numberArray[0]);

int main() {
  int x, y;

  cout << "Entrez l'indice de l'entier à diviser : " << endl;
  cin >> x;

  cout << "Entrez le diviseur : " << endl;
  cin >> y;

  try {
    int result = Test::performDivision(x, y);
    cout << "Le résultat de la division est : " << result << endl;
  } catch (const char *errorMessage) {
    cerr << errorMessage << endl;
    return 1; // Quitter avec un code d'erreur.
  }

  return 0;
}