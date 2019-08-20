/*
78. Subsets 			Medium

	Given a set of distinct integers, nums, return all possible subsets (the power set).

	Note 
		The solution set must not contain duplicate subsets.

Example:

	Input 
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

void showVectors(vector<vector<int> > nums) {

	for (int i=0; i<nums.size(); i++) {

		for (int j=0; j<nums[i].size(); j++) {

			cout << nums[i][j] << " ";
		}

		cout << endl;
	}
}

void backtracking(vector<int>& nums, vector<vector<int>> &res) {
	
}

vector<vector<int>> subsets(vector<int>& nums) {

	int n = nums.size();

}

int main() {

	vector<int> nums;

	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	vector<vector<int>> response = subsets(nums);

	showVectors(nums);

	return 0;
}