#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n = 2;
	int i, j;

	vector<int> response(n);

	cout << "Hello" << endl;

	for (i=0; i<n; i++)
		response[i] = i+1;

	for (i=0; i<n; i++)
		cout << response[i] <<  " ";

	cout << endl << endl;

	for (i=0; i<n/4; i++) {
		for (j=0; j<4; j++) {
			cout << response[4*i+j] << "\t";
		}
		cout << endl;
	}


	for (j=0; j<n%4; j++)
		cout << response[4*i+j] << "\t";

	cout << endl;

	return 0;
}
