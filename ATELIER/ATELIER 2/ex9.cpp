#include <iostream>
#include <cmath>
using namespace std;

class vecteur3d {
private:
    float x, y, z;
public:
    vecteur3d(float a=0, float b=0, float c=0) : x(a), y(b), z(c) {}
    void afficher() const { cout << "(" << x << ", " << y << ", " << z << ")"; }
    vecteur3d somme(const vecteur3d& v) const { return vecteur3d(x+v.x, y+v.y, z+v.z); }
    float produit(const vecteur3d& v) const { return x*v.x + y*v.y + z*v.z; }
    bool coincide(const vecteur3d& v) const { return x==v.x && y==v.y && z==v.z; }
    float norme() const { return sqrt(x*x + y*y + z*z); }
    vecteur3d normax(const vecteur3d& v) const { return (this->norme()>=v.norme())?*this:v; }
    const vecteur3d* normaxAdresse(const vecteur3d* v) const { return (this->norme()>=v->norme())?this:v; }
    const vecteur3d& normaxReference(const vecteur3d& v) const { return (this->norme()>=v.norme())?*this:v; }
};

int main() {
    vecteur3d v1(2,3,4), v2(1,5,2);
    cout << "v1="; v1.afficher(); cout << "\n";
    cout << "v2="; v2.afficher(); cout << "\n";
    vecteur3d vs = v1.somme(v2);
    cout << "Somme: "; vs.afficher(); cout << "\n";
    cout << "Produit scalaire: " << v1.produit(v2) << "\n";
    cout << "Coincident? " << (v1.coincide(v2)? "Oui":"Non") << "\n";
    cout << "Norme v1: " << v1.norme() << ", Norme v2: " << v2.norme() << "\n";
    cout << "Normax (valeur): "; v1.normax(v2).afficher(); cout << "\n";
    cout << "Normax (adresse): "; v1.normaxAdresse(&v2)->afficher(); cout << "\n";
    cout << "Normax (reference): "; v1.normaxReference(v2).afficher(); cout << "\n";
    return 0;
}
