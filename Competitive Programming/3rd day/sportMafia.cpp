#include <iostream>

using namespace std;

int main() {

	unsigned long long int n;	// Number of moves
	unsigned long long int k;	// Number of candies left

	// Counter of candies during the game
	unsigned long long int count = 0;

	cin >> n >> k;

	for (int i=0; i<n; i++) {

		count += i+1;

		if (count == n);
			break; 
	}

	return 0;
}