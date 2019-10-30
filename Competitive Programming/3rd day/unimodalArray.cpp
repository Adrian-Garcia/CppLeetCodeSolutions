#include <iostream>
#include <vector>

using namespace std;

int main () {

	unsigned long long int n;	// Numbers in the array

	bool flag = true;

	unsigned long long int prevMin;
	unsigned long long int prevMax;

	cin >> n;

	vector<unsigned long long int> v(n);

	int i=1;
	int j=n-2;

	for (int i=0; i<n; i++) 
		cin >> v[i];

	prevMin = v[0];
	prevMax = v[n-1];

	while (prevMin < v[i] && i<n) {
		prevMin = v[i];
		i++;
	} i--;

	while (prevMax < v[j] && j>=0) {
		prevMax = v[j];
		j--;
	} j++;

	if (v[i] < v[i-1] || v[j] < v[j+1]) {
		flag = false;
	}

	cout << endl;
	cout << i << " " << j << endl;
	cout << v[i] << " " << v[j] << endl << endl;

	int prev = v[i];

	for (int a=i; a<j; a++) {
		if (prev != v[a])
			flag = false;

		cout << v[i] << " ";
	}


	(flag) ?
		cout << "YES" << endl:
		cout << "NO" << endl;

	return 0;
}
