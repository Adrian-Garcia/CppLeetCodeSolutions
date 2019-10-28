#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

	unsigned long long int n;
	unsigned long long int xCoin;
	unsigned long long int yCoin;

	cin >> n;
	cin >> yCoin >> xCoin;

	unsigned long long int movesWhite = 0;
	unsigned long long int movesBlack = 0;

	movesWhite = min(xCoin, yCoin) - 1;
	movesWhite += max(xCoin, yCoin) - min(xCoin, yCoin);

	movesBlack = n - max(xCoin, yCoin);
	movesBlack += max(xCoin, yCoin) - min(xCoin, yCoin);

	// cout << movesWhite << " " << movesBlack << endl;

	if (movesWhite <= movesBlack)
		cout << "White" << endl;

	else
		cout << "Black" << endl;

	return 0;
}