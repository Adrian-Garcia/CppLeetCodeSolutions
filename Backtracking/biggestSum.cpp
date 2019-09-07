/*
Biggest sum 		Medium

	Given a vector, find the biggest sum possible using the numbers in the vector

	Example 1:
		Input: [1, 2, 3]
		Output: 6

	Example 2:
		Input: [1, -2, 3] 
		Output: 4
*/
#include <iostream> 
#include <vector>
#include <limits.h>

using namespace std;

int backtracking(vector<int> nums, int i) {
	if (i == 0) return 0;
	return max(nums[i-1]+backtracking(nums, i-1), backtracking(nums, i-1));
}

int getMax(vector<int> nums) {

	return backtracking(nums, nums.size());
}

int main() {
	
	vector<int> nums;

	nums.push_back(-1);
	nums.push_back(-2);
	nums.push_back(-3);

	cout << getMax(nums) << endl;

	return 0;
}