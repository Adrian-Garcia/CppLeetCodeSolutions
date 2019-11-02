#include <iostream>
#include <string>

using namespace std;

int main() {

	int n;
	int d;
	
	int cont = 0;

	int i;
	int j;
	int last;

	bool flag;

	string v;

	cin >> n >> d >> v;

	for (i=1; i<n; i++) {

		flag = false;

		for (j=i; j<d+1 && j<n; j++) {

			cout << v[j];

			if (v[j] == 1) {
				flag = true;
				last = j;
			}
		}

		if (flag) {
			cout << endl << "UNO" << endl;
			break;
		}

		cont++;
		i = last;
	}

	if (flag)
		cout << -1 << endl;

	else
		cout << cont << endl;;

	return 0;
}