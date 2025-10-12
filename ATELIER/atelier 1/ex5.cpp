#include <iostream>
using namespace std;

void remplir(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << " : ";
        cin >> *(arr + i);
    }
}

void afficher(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int& trouverMax(int* arr, int n) {
    int* maxElement = arr;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > *maxElement) {
            maxElement = arr + i;
        }
    }
    return *maxElement;
}

void inverser(int* arr, int n) {
    int* debut = arr;
    int* fin = arr + n - 1;
    while (debut < fin) {
        int temp = *debut;
        *debut = *fin;
        *fin = temp;
        debut++;
        fin--;
    }
}

int main() {
    int n;
    cout << "Donnez la taille du tableau : ";
    cin >> n;

    int* arr = new int[n];

    remplir(arr, n);

    cout << "Tableau initial : ";
    afficher(arr, n);

    int& max = trouverMax(arr, n);
    cout << "Le plus grand element : " << max << endl;

    cout << "Je modifie le maximum : ";
    cin >> max;

    cout << "Apres modification : ";
    afficher(arr, n);

    inverser(arr, n);
    cout << "Tableau inverse : ";
    afficher(arr, n);

    delete[] arr;

    return 0;
}