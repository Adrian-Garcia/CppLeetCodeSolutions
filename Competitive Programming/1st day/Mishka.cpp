#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	int k;

	cin >> n;
	cin >> k;

	int counter = 0;

	vector<int> problems(n);

	for (int i=0; i<n; i++)
		cin >> problems[i];

	int i=0; 
	int j=n-1;

	while (problems[i] <= k && i < n) {
		i++;
		counter++;
	}

	while (problems[j] <= k && j >= 0) {
		
		if (i == j+1)
			break;

		j--;
		counter++;
	}

	if (i == j && problems[i] <= k)
		counter++;

	cout << counter << endl;
}