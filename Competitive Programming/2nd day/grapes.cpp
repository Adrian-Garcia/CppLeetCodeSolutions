#include <iostream>

using namespace std;

int main() {

	// Desired eat grapes
	long long int x, y, z;

	// Amount of grapes
	long long int a, b, c;

	// Rest of grapes inf diferent times
	long long int restA, restB, restC;
	
	bool flag = true;

	// A Green
	// B Purple
	// C BLack

	// X Only green
	// Y Anything but black
	// Z Any kind of grapes

	cin >> x >> y >> z;
	cin >> a >> b >> c;
	
	restA = a - x;
	// cout << restA << endl;

	if (restA < 0)
		flag = false;

	restB = restA + b - y ;
	// cout << restB << endl;

	if (restB < 0)
		flag = false;

	restC = restB + c - z;
	// cout << restC << endl;

	if (restC < 0)
		flag = false;


	// cout << endl << endl;
	(flag) ?
		cout << "YES" << endl: 
		cout << "NO" << endl; 

	return 0;
}