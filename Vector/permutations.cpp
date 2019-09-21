/*
46. Permutations 			Medium

	Given a collection of distinct integers, return all possible permutations.

	Example:

	Input: 
		[1,2,3]
	
	Output:
		[
		  [1,2,3],
		  [1,3,2],
		  [2,1,3],
		  [2,3,1],
		  [3,1,2],
		  [3,2,1]
		]

*/
#include <iostream>
#include <vector>

using namespace std;

void swapNums(vector<vector<int> > &permutations, vector<int> nums, int i, int j) {

	cout << 2 << endl;

	swap(nums[i], nums[j]);
	permutations.push_back(nums);
}

vector<vector<int> > permute(vector<int>& nums) {

	cout << 1 << endl;

	vector<vector<int> > permutations;

	permutations.push_back(nums);
	for (int i=0; i<nums.size(); i++) 
		for (int j=i; j<nums.size(); j++) 
			if (i != j) swapNums(permutations, nums, i, j);
}

int main() {

	vector<int> nums;
	
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	vector<vector<int> > permutations = permute(nums);

	for (int i=0; i<permutations.size(); i++) {

		for (int j=0; j<permutations[i].size(); j++) {
			
			cout << permutations[i][j] << " ";
		} cout << endl;
	}

	return 0;
}