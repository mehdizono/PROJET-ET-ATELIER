#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n = 1;
void nbr_appel() {
	cout << "appel numero" << n << endl;
	n++;
}
int main() {
	nbr_appel();
	nbr_appel();
	nbr_appel();

}