#include <iostream>
#include <vector>

using namespace std;

int main () {

	unsigned long long int n;	// Numbers in the array
	
	bool flag = true;

	cin >> n;

	vector<long long int> v(n);

	for (int i=0; i<n; i++) 
		cin >> v[i];

	long long int maxNum = v[0];	
	unsigned long long int maxPos = 0;
	unsigned long long int right;

	for (int i=0; i<n; i++) {

		if (v[i] > maxNum) {
			maxNum = v[i];
			maxPos = i;
		}
	}


	right = maxPos;

	for (int i=maxPos; i<n; i++) {

		if (v[i] == maxNum) 
			right = i;
		
		else
			break;
	} 

	// cout << maxPos << " " << right;

	for (int i=maxPos; i>0 && flag; i--) 
		if (v[i-1] >= v[i])
			flag = false;

	for (int i=right; i<n-1 && flag; i++)
		if (v[i+1] >= v[i])
			flag = false;

	(flag) ?
		cout << "YES" << endl:
		cout << "NO" << endl;

	return 0;
}
