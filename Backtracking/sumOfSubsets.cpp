/*
	Sum of Subsets
		
		Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to 
		given sum.

		Example 
			Input:  
				set[] = {3, 34, 4, 12, 5, 2}, sum = 9
			
			Output:  
				True  //There is a subset (4, 5) with sum 9.
*/
#include <iostream>

using namespace std;

bool isSubsetSum(int set[], int n, int sum) {

	if (sum == 0)
		return true;

	if (n == 0 && sum != 0)
		return false;

	if (set[n-1] > sum)
		return isSubsetSum(set, n-1, sum);

	return (isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]));
}

void backtracking(int set[], int n, int sum) {

	if (sum == 0) {
		cout << "SI" << endl;
		return;
	}

	if (n == 0 && sum != 0) {
		cout << "NO" << endl;
		return;
	}

	if (set[n-1] > sum)
		backtracking(set, n-1, sum);

	backtracking(set, n-1, sum);
	backtracking(set, n-1, sum-set[n-1]);			 
}

int main() {

	int set[] = {1,2,3};
	int sum = 6;
	int n = sizeof(set)/sizeof(int);

	backtracking(set, n, sum);

	// isSubsetSum(set, n, sum) ?
	// 	cout << "SI" << endl:
	// 	cout << "NO" << endl;


	return 0;
}
