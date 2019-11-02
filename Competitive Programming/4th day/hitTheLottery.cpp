#include <iostream>

using namespace std;

int main() {

	int n;
	int count = 0;
	cin >> n;

	if (n/100) {
		count += n/100;
		n %= 100;
		// cout << 100 << " " << n << endl;
	}

	if (n/20) {
		count += n/20;
		n %= 20;
		// cout << 20 << " " << n << endl;
	}

	if (n/10) {
		count += n/10;
		n %= 10;
		// cout << 10 << " " << n << endl;
	}

	if (n/5) {
		count += n/5;
		n %= 5;
		// cout << 5 << " " << n << endl;
	}

	cout << count + n << endl;

	return 0;
}