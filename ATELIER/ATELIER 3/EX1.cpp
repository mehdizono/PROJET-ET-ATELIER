

#include <iostream>
using namespace std;


struct node {
	int data;
	node* next;
};

class liste {
	node* tete;

public:
	//constructeur
	liste() {
		tete = nullptr;
	}
	//ajouter_en_tete
	void ajouter_en_tete(int n) {
		node* newnode = new node();
		newnode->data = n;
		newnode->next = tete;
		tete = newnode;
		cout << "ajouter au debut:" << n << endl;
	}
	//	int supprimer_en_tete() 
	int supprimer_en_tete() {
		if (tete == nullptr) {
			cout <<"liste vide !" << endl;
			return -1;
		}
		node* tmp = tete;
		int valeur = tmp->data;
		tete = tete->next;
		delete tmp;
		return valeur;
	}

	// afficher le contenu de la pile
	void afficher() {
		node* courant = tete;
		cout << "Contenu de la liste: ";
		while (courant != nullptr) {
			cout << "->" << courant->data ;
			courant = courant->next;
		}
		cout << endl;
	}
};
int main()
{
	liste L;
	L.ajouter_en_tete(20);
	L.ajouter_en_tete(7);
	L.ajouter_en_tete(15);
	int val= L.supprimer_en_tete();
	cout << "supprimer en tete:" << val << endl; 
	L.afficher();


	return 0;
	
}
