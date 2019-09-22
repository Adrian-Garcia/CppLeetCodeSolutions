/*
78. Subsets 				Medium

	Given a set of distinct integers, nums, return all possible subsets (the power set).

	Note: 
		The solution set must not contain duplicate subsets.

	Example:

		Input: 
			nums = [1,2,3]
		
		Output:
			[
			  [3],
			  [1],
			  [2],
			  [1,2,3],
			  [1,3],
			  [2,3],
			  [1,2],
			  []
			]
*/
#include <iostream>
#include <vector>

using namespace std;

void backtracking(vector<vector<int> >& subsets, vector<int> nums, vector<int> sub, int i) {

	if (i >= nums.size())
		return;

	backtracking(subsets, nums, sub, i+1);
	sub.push_back(nums[i]);
	subsets.push_back(sub);
	backtracking(subsets, nums, sub, i+1);
}

vector<vector<int> > subsets(vector<int>& nums) {

	vector<vector<int> > subsets;
	vector<int> sub;

	backtracking(subsets, nums, sub, 0);
	subsets.push_back(vector<int>());
	return subsets;	
}

int main() {

	vector<int> nums;

	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	vector<vector<int> > combinations = subsets(nums);

	for (int i=0; i<combinations.size(); i++) {
		for (int j=0; j<combinations[i].size(); j++) {
			cout << combinations[i][j] << " ";
		} cout << endl; 	
	}

	return 0;
}