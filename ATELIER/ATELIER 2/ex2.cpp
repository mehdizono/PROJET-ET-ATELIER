#include <iostream>
#include <string>
#include <vector>
using namespace std;
int multiple_2(int n) {
	if (n % 2 == 0)
		return 1;
	else
		return 0;
}
int multiple_3(int n) {
	if (n % 3 == 0)
		return 1;
	else
		return 0;
}
int main() {
	int n,n2,n3;
	cout << "donnez un entier : ";
	cin >> n;
	cout << endl;
	n2 = multiple_2(n);
	n3 = multiple_3(n);
	if (n2 == 1)
		cout << "il est pair" << endl;
	if(n3==1)
		cout << "il est multiple de 3" << endl;
	if(n2==1 && n3==1)
		cout << "il est divisible par 6" << endl;
	return 0;
}