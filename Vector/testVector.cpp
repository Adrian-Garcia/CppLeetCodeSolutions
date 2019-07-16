#include <iostream>
#include <vector>

using namespace std;

int main() {

	int Mat[3][3];

	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			cin >> Mat[i][j];

	cout << endl << endl;
	
	for (int i=0; i<3; i++) {
		
		for (int j=0; j<3; j++) {
			cout << Mat[i][j] << " ";			
		}

		cout << endl;
	}

	cout << endl << endl;

	cout << Mat[1][0] << " ";
	cout << Mat[0][1];

	return 0;
}