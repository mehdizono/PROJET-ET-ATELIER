#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Entrez la taille du tableau : ";
    cin >> n;

    int* tab = new int[n];
    cout << "Entrez " << n << " entiers : ";
    for (int i = 0; i < n; i++) cin >> tab[i];

    int* tabCarre = new int[n];
    for (int i = 0; i < n; i++) tabCarre[i] = tab[i] * tab[i];

    delete[] tab;

    cout << "Tableau des carres : ";
    for (int i = 0; i < n; i++) cout << tabCarre[i] << " ";
    cout << endl;

    delete[] tabCarre;
    return 0;
}
