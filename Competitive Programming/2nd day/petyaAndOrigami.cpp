#include <iostream>
#include <cmath>

using namespace std;

int main() {

	unsigned long long int n;							// Number of friends
	unsigned long long int k; 						// Number of sheets
	unsigned long long int c = 0;

	cin >> n >> k;

	// 2 red
	// 5 green
	// 8 blue

	c += (n*2) / k;
	c += ((n*2) % k == 0) ?
		0 : 1;

	c += (n*5) / k;
	c += ((n*5) % k == 0) ?
		0 : 1;

	c += (n*8) / k;
	c += ((n*8) % k == 0) ?
		0 : 1;

	cout << c << endl;

	return 0;
}