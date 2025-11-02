#include <iostream>
#include <string>
using namespace std;

//
// ─── Déclaration de la fonction globale avant utilisation ───────────
//
float calculInteret(float solde, float taux);

//
// ─── CLASSE CLIENT ─────────────────────────────────────────────
//
class Client {
    int id;
    string nom;
    string prenom;

public:
    Client() {
        id = 0;
        nom = "";
        prenom = "";
        cout << "Constructeur Client par defaut appele." << endl;
    }

    Client(int i, string n, string p) {
        id = i;
        nom = n;
        prenom = p;
        cout << "Constructeur Client avec parametres appele pour "
             << prenom << " " << nom << "." << endl;
    }

    Client(const Client& c) {
        id = c.id;
        nom = c.nom;
        prenom = c.prenom;
        cout << "Constructeur de copie Client appele pour "
             << prenom << " " << nom << "." << endl;
    }

    ~Client() {
        cout << "Destructeur Client appele pour " << prenom << " " << nom << "." << endl;
    }

    void Afficher() const {
        cout << "Client #" << id << " : " << prenom << " " << nom << endl;
    }
};

//
// ─── CLASSE COMPTE ─────────────────────────────────────────────
//
class Compte {
    int numero;
    float solde;
    Client* client;                     
    static int nbComptes;               

public:
    Compte() {
        numero = 0;
        solde = 0.0;
        client = nullptr;
        nbComptes++;
        cout << "Constructeur Compte par defaut appele." << endl;
    }

    Compte(int num, float s, const Client& c) {
        numero = num;
        solde = s;
        client = new Client(c);
        nbComptes++;
        cout << "Constructeur Compte avec parametres appele." << endl;
    }

    Compte(const Compte& c) {
        numero = c.numero;
        solde = c.solde;
        client = new Client(*c.client);
        nbComptes++;
        cout << "Constructeur de copie Compte appele." << endl;
    }

    ~Compte() {
        delete client;
        nbComptes--;
        cout << "Destructeur Compte appele pour le compte #" << numero << endl;
    }

    void Afficher() const {
        cout << "Compte #" << numero << " | Solde : " << solde << " MAD" << endl;
        if (client != nullptr) {
            cout << "→ ";
            client->Afficher();
        } else {
            cout << "Aucun client associe." << endl;
        }
    }

    static void afficherNbComptes() {
        cout << "Nombre total de comptes existants : " << nbComptes << endl;
    }

    void appliquerInteret(float taux) {
        solde = calculInteret(solde, taux);
    }

    friend float calculInteret(float solde, float taux);
};

int Compte::nbComptes = 0;

//
// ─── FONCTION GLOBALE : calculInteret ──────────────────────────
//
inline float calculInteret(float solde, float taux) {
    return solde + solde * taux / 100;
}

//
// ─── FONCTION PRINCIPALE MAIN ──────────────────────────────────
//
int main() {
    cout << "=== Creation des clients et comptes ===" << endl;

    Client c1(1, "Abdenbi", "Mehdi");
    Client c2(2, "alaoui", "Amine");

    Compte::afficherNbComptes();

    Compte cp1(1001, 2000.0, c1);
    Compte cp2(1002, 5000.0, c2);

    cout << endl << "=== Affichage des comptes ===" << endl;
    cp1.Afficher();
    cp2.Afficher();

    Compte::afficherNbComptes();

    cout << endl << "=== Copie d'un compte ===" << endl;
    Compte cp3(cp1);
    cp3.Afficher();

    Compte::afficherNbComptes();

    cout << endl << "=== Application des interets (5%) ===" << endl;
    cp1.appliquerInteret(5);
    cp1.Afficher();

    cout << endl << "=== Suppression d'un compte ===" << endl;
    {
        Compte temp(2000, 1000, c1);
    } // temp est détruit automatiquement ici

    Compte::afficherNbComptes();

    cout << endl << "=== Fin du programme ===" << endl;
    return 0;
}


