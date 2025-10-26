#include <iostream>
#include <string>
using namespace std;

void permuter(string s, int debut, int fin) {
    if (debut == fin) cout << s << endl;
    else {
        for (int i = debut; i <= fin; i++) {
            swap(s[debut], s[i]);
            permuter(s, debut + 1, fin);
            swap(s[debut], s[i]);
        }
    }
}

int main() {
    string chaine;
    cout << "Entrez une chaine : ";
    cin >> chaine;
    permuter(chaine, 0, chaine.size() - 1);
    return 0;
}
