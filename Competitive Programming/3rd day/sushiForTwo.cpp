#include <iostream>
#include <vector>

using namespace std;

int main() {

	unsigned long long int n;
	cin >> n;

	vector<unsigned long long int> v(n, 0);
	vector<unsigned long long int> nums(100000, 0);

	int res; 
	int maxNum = -1;
	unsigned long long int pos = 0;
	
	nums[0] = 0;

	for(int i=0; i<n; i++)
		cin >> v[i];
	
	for(int i=0; i<n-1; i++) {
		
		if(v[i] != v[i+1]) 
			nums[pos++] = i+1;

		nums[pos] = n;
	}
	
	res = -1;

	if (1 < pos) {
		
		for(int i=1; i<pos; i++) {

			maxNum = min(nums[i]-nums[i-1], nums[i+1]-nums[i]);
			res = max(maxNum, res);
		}
	}

	else 
		res = 0;

	cout << res*2 << endl;

	return 0;
}