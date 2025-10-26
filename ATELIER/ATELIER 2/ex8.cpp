#include <iostream>

using namespace std;

class voiture {
public:
	string marque;
	string modele;
	int annee;
	float kilometrage;
	float vitesse;

	voiture() {}
	voiture(string m, string mo, int an, float kil, float vit) {
		marque = m;
		modele = mo;
		annee = an;
		kilometrage = kil;
		vitesse = vit;
	}
	void accelerer(float valeur) {
		vitesse = vitesse + valeur;
	}
	void freiner(float valeur) {
		if (vitesse >= valeur)
			vitesse = vitesse - valeur;
	}
	void afficherInfo() {
		cout << "marque:" << marque <<endl;
		cout << "modele:" << modele << endl;
		cout << "annee:" << annee << endl;
		cout << "kilometrage:" << kilometrage << endl;
		cout << "vitesse:" << vitesse << endl;

	}
	void avencee(float distance) {
		kilometrage = kilometrage + distance;
	}
	~voiture() {
		cout << "la voiture est detruite.";
	}
};

int main() {
	voiture v1("dacia", "logan", 2009, 600, 100);
	v1.afficherInfo();
	v1.accelerer(20);
	v1.freiner(10);
	v1.avencee(100);
	v1.afficherInfo();
	

	return 0;
}
