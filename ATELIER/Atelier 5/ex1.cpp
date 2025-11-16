#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <string>
#include <vector>

using namespace std;

set<int> createIntSet() {
  set<int> intSet;
  for (int i = 1; i <= 100; ++i) {
    intSet.insert(i);
  }
  return intSet;
}

bool isPresentInSet(const set<int> &searchSet, int valueToFind) { return searchSet.count(valueToFind) > 0; }

bool isPresentInRange(set<int>::iterator beginIt, set<int>::iterator endIt, int valueToFind) {
  return find(beginIt, endIt, valueToFind) != endIt;
}

template <typename Iterator, typename T>
bool isPresentInContainer(Iterator beginIt, Iterator endIt, const T &valueToFind) {
  // find() fonctionne avec n'importe quelle paire d'itérateurs
  return find(beginIt, endIt, valueToFind) != endIt;
}

int main() {
  set<int> intSet = createIntSet();
  cout << "Ensemble créé, 1 à 100" << endl;

  // isPresentInSet()
  cout << "50 dans l'ensemble ? :" << (isPresentInSet(intSet, 50) ? "Oui" : "Non") << endl;
  cout << "150 dans l'ensemble ? :" << (isPresentInSet(intSet, 150) ? "Oui" : "Non") << endl;

  // isPresentInRange()
  cout << "75 dans la plage d'itérateurs ? [1-100] :"
       << (isPresentInRange(intSet.begin(), intSet.end(), 75) ? "Oui" : "Non") << endl;
  cout << "70 dans la plage d'itérateurs ? [10-70[ ([10-69]) :"
       << (isPresentInRange(intSet.find(10), intSet.find(70), 70) ? "Oui" : "Non") << endl;
  cout << "69 dans la plage d'itérateurs ? [10-70[ ([10-69]) :"
       << (isPresentInRange(intSet.find(10), intSet.find(70), 69) ? "Oui" : "Non") << endl;

  // isPresentInContainer()
  vector<string> stringVector = {"Aha", "Ehe", "Uhu", "Oho"};
  string targetString = "Ehe";
  cout << "Vecteur de chaînes : '" << targetString << "' présent ? "
       << (isPresentInContainer(stringVector.begin(), stringVector.end(), targetString) ? "Oui" : "Non") << endl;

  list<int> intList = {10, 20, 30, 40, 50};
  int targetInt = 30;
  cout << "Liste d'entiers : " << targetInt << " présent ? "
       << (isPresentInContainer(intList.begin(), intList.end(), targetInt) ? "Oui" : "Non") << endl;

  float floatArray[] = {1.5f, 2.7f, 3.9f, 4.1f};
  float targetFloat = 3.9f;
  cout << "Tableau classique de flottants : " << targetFloat << " présent ? "
       << (isPresentInContainer(begin(floatArray), end(floatArray), targetFloat) ? "Oui" : "Non") << endl;

  return 0;
}