# 🧩 Atelier 1 — POO C++ (Ex1 à Ex4)

## 📘 Exercices
### 🔹 Exercice 1 à Exercice 4
[📄 Atelier 1 - POO C++ (ex1-ex4) — Mehdi Abdenbi](https://github.com/user-attachments/files/22868256/Atelier.1.-.POO.C%2B%2B.ex1-ex4.mehdi.abdenbi.pdf)

### 🔹 Exercice 5 — Tableaux dynamiques
[💻 exercice5.cpp]()#include <iostream>
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

---

## 📂 Documents de référence
- [📑 Énoncés originaux (PDF)](https://github.com/user-attachments/files/22846114/Atelier.1.-.POO.C%2B%2B.pdf)


## 📄 Document
- [Énoncés originaux (PDF)](./Atelier%201%20-%20PO[Atelier 1 - POO C++.pdf](https://github.com/user-attachments/files/22846114/Atelier.1.-.POO.C%2B%2B.pdf)
O%20C++.pdf)
