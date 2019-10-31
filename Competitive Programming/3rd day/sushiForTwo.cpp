#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(100000, 0);
	vector<int> nums(100000, 0);

	int l1,l2;
	int res=-1; 

	int maxNum=-1;
	int j = 1;
	
	nums[0] = 0;

	for(int i=0; i<n; i++)
		cin >> v[i];
	
	for(int i=0; i<n-1; i++) {
		
		if(v[i] != v[i+1]) {
			nums[j] = i+1;
			j++;
		}
		nums[j] = n;
	}
	
	if (j > 1) {
		
		for(int i=1; i<j; i++) {
			
			l1=nums[i]-nums[i-1];
			l2=nums[i+1]-nums[i];

			maxNum = min(l1,l2);

			if(maxNum > res)
				res=maxNum;
		}
		cout << res*2;
	}
	return 0;
}

/*
#include <iostream>
#include <vector>

using namespace std;

int main () {

	long long int n;	// Numbers in the array
	cin >> n;
	vector<long long int> v(n+1);

	for (int i=1; i<=n; i++) 
		cin >> v[i];

	long long int first = 1;
	long long int second = 1;
	long long int res;

	for (int i=2; i<=n; i++) {

		if (v[i] == v[i-1]) {
			
			if (v[i] == 1)
				first++;

			if (v[i] == 2)
				second++;
		}

		if (v[i] != v[i-1]) {

			if (v[i] == 1) {
				res = max(min(first, second), res);
				second = 1;
			}

			if (v[i] == 2) {

				res = max(min(first, second), res);
				first = 1;
			}
		}
	}

	res = max(min(first, second), res);
	cout << res <<endl;

	return 0;
}
*/