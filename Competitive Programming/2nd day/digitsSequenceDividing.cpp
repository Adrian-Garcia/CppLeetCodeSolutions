#include <iostream>
#include <string>

using namespace std;

int main() {
	
	unsigned long long int total;
	unsigned long long int size;
	unsigned long long int last;
	unsigned long long int j = 0;

	string number;

	cin >> total;

	for (int i=0; i<total; i++) {

		cin >> size >> number;

		for (int i=0; i<size; i++, j++) {

			if (i == 0) {
				last = stoi(number.substr(i, j));
			

				if () {
					
				}
			}

			else {
			}
		}
	}

	return 0;
}