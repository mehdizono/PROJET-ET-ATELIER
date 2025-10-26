#include <iostream>
using namespace std;

class Complexe {
private:
    float re, im;
public:
    Complexe(float r=0,float i=0):re(r),im(i){}
    void afficher() const { cout << re << (im>=0?" + ":" - ") << fabs(im) << "i"; }
    void saisir() { cout<<"Partie reelle: ";cin>>re;cout<<"Partie imaginaire: ";cin>>im; }
    Complexe addition(const Complexe& c) const { return Complexe(re+c.re, im+c.im); }
    Complexe soustraction(const Complexe& c) const { return Complexe(re-c.re, im-c.im); }
    Complexe multiplication(const Complexe& c) const { return Complexe(re*c.re - im*c.im, re*c.im + im*c.re); }
    Complexe division(const Complexe& c) const { float d=c.re*c.re+c.im*c.im; return Complexe((re*c.re+im*c.im)/d,(im*c.re-re*c.im)/d); }
    bool egal(const Complexe& c) const { return (re==c.re && im==c.im); }
};

int main() {
    Complexe c1, c2, res;
    int choix;
    cout<<"=== Calcul sur nombres complexes ===\n";
    cout<<"Premier nombre:\n"; c1.saisir();
    cout<<"Deuxieme nombre:\n"; c2.saisir();
    cout<<"\n1.Addition\n2.Soustraction\n3.Multiplication\n4.Division\n5.Egalite\nChoix: ";
    cin>>choix;
    switch(choix){
        case 1: res=c1.addition(c2); cout<<"Resultat: "; res.afficher(); break;
        case 2: res=c1.soustraction(c2); cout<<"Resultat: "; res.afficher(); break;
        case 3: res=c1.multiplication(c2); cout<<"Resultat: "; res.afficher(); break;
        case 4: res=c1.division(c2); cout<<"Resultat: "; res.afficher(); break;
        case 5: cout<<(c1.egal(c2)?"Egaux":"Differents"); break;
        default: cout<<"Choix invalide";
    }
    cout<<endl; return 0;
}
