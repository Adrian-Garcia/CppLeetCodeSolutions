#include <iostream>

using namespace std;

int main() {

	unsigned long long int n;
	long long int val;
	long long int prev;
	unsigned long long int cont = 1;
	unsigned long long int maxCont = 0;

	cin >> n;
	cin >> prev;

	for (int i=1; i<n; i++) {
		
		cin >> val;

		if (prev <= val) 
			cont++;

		else {
			maxCont = max(maxCont, cont);
			cont = 1;
		}

		prev = val;
	}

	maxCont = max(maxCont, cont);

	cout << maxCont << endl;

	return 0;
}