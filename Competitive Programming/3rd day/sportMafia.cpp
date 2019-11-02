#include<iostream>

using namespace std;

bool search(long long int val, long long int n, long long int k) {
	
	long long int total = 0;
	
	for(int i=0; i<n-val; i++)
		total += i+1;
	
	if(total-val > k)
		return true;
	
	else
		return false;
}
int main() {

	long long int n, k;

	cin >> n >> k;
		
	long long int low = 0;
	long long int big = n-1;
	long long int mid = low + (big - low)/2;
	
	while (big >= low) {
		
		mid = low + (big - low)/2;
		
		if(search(mid, n, k))
			low = mid+1;
		
		else
			big = mid-1;
	}

	cout << low << endl;

	return 0;
}