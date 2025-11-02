#include <iostream>
using namespace std;


class Fichier {
    char* P;        
    int taille;   

public:
    // Constructeur
    Fichier() {
        P = nullptr;
        taille = 0;
        cout << "Constructeur appele." << endl;
    }

    // Destructeur
    ~Fichier() {
        delete[] P; 
        cout << "Destructeur appele, memoire liberee." << endl;
    }

    // Méthode Creation : allouer la mémoire
    void Creation(int n) {
        taille = n;
        P = new char[n]; // allocation dynamique
        cout << "Creation d'un espace de " << n << " octets." << endl;
    }

    
    void Remplit() {
        if (P == nullptr) {
            cout << "Erreur : memoire non allouee !" << endl;
            return;
        }

        for (int i = 0; i < taille; i++) {
    P[i] = '0' + (i % 10); 
}



        cout << "Zone memoire remplie avec des donnees arbitraires." << endl;
    }

    // Méthode Affiche : 
    void Affiche() {
        if (P == nullptr) {
            cout << "Erreur : rien a afficher !" << endl;
            return;
        }

        cout << "Contenu de la zone memoire : ";
        for (int i = 0; i < taille; i++) {
            cout << P[i];
        }
        cout << endl;
    }
};


int main() {
    // Création d’un objet Fichier dynamiquement
    Fichier* f = new Fichier();

    // Appel des méthodes
    f->Creation(20);  
    f->Remplit();       
    f->Affiche();       


    delete f;

    return 0;
}

