#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ==============================
// Classe Client
// ==============================
class Client {
private:
    string nom;
    string CIN;
    int id;

public:
    // Constructeur
    Client(string n, string c, int i) : nom(n), CIN(c), id(i) {}

    // Afficher les infos du client
    void afficherInfos() const {
        cout << "Client: " << nom << " | CIN: " << CIN << " | ID: " << id << endl;
    }

    // On donne accès à certaines classes amies
    friend class CompteBancaire; 
    friend class Banque; 
};

// ==============================
// Classe CompteBancaire
// ==============================
class CompteBancaire {
private:
    int numeroCompte;
    double solde;
    string codeSecret; // Donnée confidentielle
    Client* client;    // Référence vers le client propriétaire

public:
    // Constructeur
    CompteBancaire(int num, double s, string code, Client* c)
        : numeroCompte(num), solde(s), codeSecret(code), client(c) {}

    // Dépôt d'argent
    void deposer(double montant) {
        solde += montant;
        cout << "Depot de " << montant << " DH effectué avec succès." << endl;
    }

    // Retrait d'argent
    bool retirer(double montant) {
        if (montant > solde) {
            cout << "Solde insuffisant !" << endl;
            return false;
        }
        solde -= montant;
        cout << "Retrait de " << montant << " DH effectué avec succès." << endl;
        return true;
    }

    // Transfert vers un autre compte (nécessite autorisation)
    void transferer(CompteBancaire& autre, double montant, string code) {
        if (code != codeSecret) {
            cout << "Code secret incorrect. Transfert refusé !" << endl;
            return;
        }
        if (retirer(montant)) {
            autre.deposer(montant);
            cout << "Transfert de " << montant << " DH effectué avec succès." << endl;
        }
    }

    // Afficher les informations (sans code secret)
    void afficherInfos() const {
        cout << "Compte N°" << numeroCompte
             << " | Solde: " << solde << " DH | Client: " << client->CIN << endl;
    }

    // Seules les classes amies peuvent consulter le code secret
    friend class AgentBancaire;
    friend class Banque;
};

// ==============================
// Classe AgentBancaire
// ==============================
class AgentBancaire {
private:
    string nomAgent;
    int idAgent;

public:
    AgentBancaire(string nom, int id) : nomAgent(nom), idAgent(id) {}

    // L’agent peut consulter des infos confidentielles (grâce à l’amitié)
    void consulterCompte(const CompteBancaire& c) {
        cout << "Agent " << nomAgent << " consulte le compte: " << endl;
        c.afficherInfos();
        cout << "Code secret (accès interne autorisé): " << c.codeSecret << endl;
    }

    // L’agent peut effectuer un transfert sécurisé
    void transfertAutorise(CompteBancaire& source, CompteBancaire& destination, double montant) {
        cout << "\nAgent " << nomAgent << " effectue un transfert autorisé..." << endl;
        source.transferer(destination, montant, source.codeSecret);
    }
};

// ==============================
// Classe Banque
// ==============================
class Banque {
private:
    vector<Client*> clients;
    vector<CompteBancaire*> comptes;

public:
    // Ajouter un client
    void ajouterClient(Client* c) {
        clients.push_back(c);
    }

    // Ajouter un compte
    void ajouterCompte(CompteBancaire* c) {
        comptes.push_back(c);
    }

    // Afficher tous les comptes et clients
    void afficherTout() const {
        cout << "\n=== Informations sur la banque ===" << endl;
        for (auto c : comptes) {
            c->afficherInfos();
        }
    }

    // Audit (consultation interne des soldes et codes)
    void rapportAudit() const {
        cout << "\n=== Rapport d'audit interne ===" << endl;
        for (auto c : comptes) {
            cout << "Compte " << c->numeroCompte
                 << " | Solde: " << c->solde
                 << " | Code secret: " << c->codeSecret
                 << " | Client: " << c->client->CIN << endl;
        }
    }
};

// ==============================
// Fonction principale main()
// ==============================
int main() {
    // Création d'une banque
    Banque b;

    // Création de clients
    Client c1("Safae", "AB12345", 1);
    Client c2("Khalid", "CD67890", 2);

    // Création des comptes
    CompteBancaire compte1(1001, 5000.0, "1234", &c1);
    CompteBancaire compte2(1002, 3000.0, "5678", &c2);

    // Ajout dans la banque
    b.ajouterClient(&c1);
    b.ajouterClient(&c2);
    b.ajouterCompte(&compte1);
    b.ajouterCompte(&compte2);

    // Création d'un agent bancaire
    AgentBancaire agent("Nadia", 101);

    // Consultation et opérations
    compte1.afficherInfos();
    compte1.deposer(1000);
    compte1.retirer(500);

    // Transfert entre comptes via l’agent
    agent.transfertAutorise(compte1, compte2, 1500);

    // Audit interne (réservé à la banque)
    b.afficherTout();
    b.rapportAudit();

    return 0;
}