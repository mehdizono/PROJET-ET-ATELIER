#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ===============================
// Classe de base : Ressource
// ===============================
class Ressource {
protected:
    int id;
    string titre;
    string auteur;
    int annee;

public:
    // Constructeur
    Ressource(int id, string titre, string auteur, int annee)
        : id(id), titre(titre), auteur(auteur), annee(annee) {}

    // Méthode d'affichage commune
    virtual void afficherInfos() const {
        cout << "ID: " << id << ", Titre: " << titre
             << ", Auteur: " << auteur << ", Annee: " << annee << endl;
    }

    // Méthode virtuelle pour téléchargement (sera redéfinie plus tard)
    virtual void telecharger() const {
        cout << "Cette ressource n'est pas téléchargeable." << endl;
    }

    // Accesseurs utiles pour la recherche
    string getTitre() const { return titre; }
    string getAuteur() const { return auteur; }
    int getAnnee() const { return annee; }

    // Surcharge de l'opérateur ==
    bool operator==(const Ressource& r) const {
        return (titre == r.titre && auteur == r.auteur && annee == r.annee);
    }

    // Destructeur virtuel (important pour l’héritage)
    virtual ~Ressource() {}
};

// ===============================
// Classe dérivée : Livre
// ===============================
class Livre : public Ressource {
private:
    int nbPages;

public:
    Livre(int id, string titre, string auteur, int annee, int nbPages)
        : Ressource(id, titre, auteur, annee), nbPages(nbPages) {}

    void afficherInfos() const override {
        cout << "[Livre] ";
        Ressource::afficherInfos();
        cout << "Nombre de pages: " << nbPages << endl;
    }
};

// ===============================
// Classe dérivée : Magazine
// ===============================
class Magazine : public Ressource {
private:
    int numero;

public:
    Magazine(int id, string titre, string auteur, int annee, int numero)
        : Ressource(id, titre, auteur, annee), numero(numero) {}

    void afficherInfos() const override {
        cout << "[Magazine] ";
        Ressource::afficherInfos();
        cout << "Numero: " << numero << endl;
    }
};

// ===============================
// Classe dérivée : Video
// ===============================
class Video : public Ressource {
private:
    int duree; // en minutes

public:
    Video(int id, string titre, string auteur, int annee, int duree)
        : Ressource(id, titre, auteur, annee), duree(duree) {}

    void afficherInfos() const override {
        cout << "[Video] ";
        Ressource::afficherInfos();
        cout << "Duree: " << duree << " min" << endl;
    }

    void telecharger() const override {
        cout << "Téléchargement de la vidéo : " << titre << endl;
    }
};

// ===============================
// Classe Médiathèque
// ===============================
class Mediatheque {
private:
    vector<Ressource*> ressources;

public:
    // Ajouter une ressource
    void ajouter(Ressource* r) {
        ressources.push_back(r);
    }

    // Afficher toutes les ressources
    void afficherToutes() const {
        cout << "\n=== Contenu de la Médiathèque ===" << endl;
        for (auto r : ressources) {
            r->afficherInfos();
            cout << "-----------------------------" << endl;
        }
    }

    // Rechercher une ressource par titre, auteur ou année
    void rechercher(string titre, string auteur, int annee) const {
        cout << "\n=== Résultat de la recherche ===" << endl;
        bool trouve = false;
        for (auto r : ressources) {
            if (r->getTitre() == titre && r->getAuteur() == auteur && r->getAnnee() == annee) {
                r->afficherInfos();
                trouve = true;
            }
        }
        if (!trouve)
            cout << "Aucune ressource ne correspond à la recherche." << endl;
    }

    // Comparer deux ressources (affiche si elles sont égales)
    void comparer(const Ressource& r1, const Ressource& r2) const {
        if (r1 == r2)
            cout << "Les deux ressources sont identiques." << endl;
        else
            cout << "Les deux ressources sont différentes." << endl;
    }

    // Destructeur pour libérer la mémoire
    ~Mediatheque() {
        for (auto r : ressources)
            delete r;
    }
};

// ===============================
// Fonction principale main()
// ===============================
int main() {
    // Création d'une médiathèque
    Mediatheque m;

    // Création de quelques ressources
    m.ajouter(new Livre(1, "C++ pour debutants", "Bjarne", 2015, 300));
    m.ajouter(new Magazine(2, "Science et Vie", "Equipe Rédaction", 2023, 58));
    m.ajouter(new Video(3, "Les bases de C++", "OpenClassrooms", 2020, 90));

    // Affichage de toutes les ressources
    m.afficherToutes();

    // Recherche d’une ressource
    m.rechercher("C++ pour debutants", "Bjarne", 2015);

    // Comparaison de deux ressources
    Livre l1(4, "Python facile", "Guido", 2019, 250);
    Livre l2(5, "Python facile", "Guido", 2019, 250);
    m.comparer(l1, l2);

    // Test de téléchargement
    cout << "\n=== Test du téléchargement ===" << endl;
    Video v(6, "Apprendre C++", "YouTube", 2021, 60);
    v.telecharger();

    return 0;
}