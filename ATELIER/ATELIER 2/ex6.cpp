#include <iostream>
using namespace std;

void incrementer(int* x) { (*x)++; }
void permuter(int* a, int* b) { int temp = *a; *a = *b; *b = temp; }
void incrementerRef(int& x) { x++; }
void permuterRef(int& a, int& b) { int temp = a; a = b; b = temp; }

int main() {
    int a = 5, b = 10;
    cout << "Avant incrementation : a = " << a << endl;
    incrementer(&a);
    cout << "Apres incrementation (adresse) : a = " << a << endl;
    incrementerRef(a);
    cout << "Apres incrementation (reference) : a = " << a << endl;
    cout << "\nAvant permutation : a = " << a << ", b = " << b << endl;
    permuter(&a, &b);
    cout << "Apres permutation (adresse) : a = " << a << ", b = " << b << endl;
    permuterRef(a, b);
    cout << "Apres permutation (reference) : a = " << a << ", b = " << b << endl;
    return 0;
}
