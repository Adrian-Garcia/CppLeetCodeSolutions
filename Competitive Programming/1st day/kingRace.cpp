#include <iostream>

using namespace std;

int main() {

	double n;
	double xCoin;
	double yCoin;

	cin >> n;
	cin >> yCoin >> xCoin;

	yCoin--;
	xCoin--;

	double xWhite = 0;
	double yWhite = 0;
	double movesWhite = 0;

	double xBlack = n-1;
	double yBlack = n-1;
	double movesBlack = 0;

	// White king moves in diagonal
	while (yCoin > yWhite && xCoin > xWhite) {

		xWhite++;
		yWhite++;
		movesWhite++;
	}

	// white king moves in y
	while (yCoin > yWhite) {
		yWhite++;
		movesWhite++;
	}

	// white king moves in x 
	while (xCoin > xWhite) {
		xWhite++;
		movesWhite++;
	}

	// ---------------------------------------------

	// Black king moves in diagonal
	while (yCoin < yBlack && xCoin < xBlack) {
		xBlack--;
		yBlack--;
		movesBlack++;
	}

	// white king moves in y
	while (yCoin < yBlack) {
		yBlack--;
		movesBlack++;
	}

	// white king moves in x 
	while (xCoin < xBlack) {
		xBlack--;
		movesBlack++;
	}

	if (movesWhite <= movesBlack) 
		cout << "White" << endl;
	else
		cout << "Black" << endl;



	return 0;
}