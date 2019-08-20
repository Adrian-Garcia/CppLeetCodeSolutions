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

void backtracking(vector<int>& nums, vector<int>& sub, vector<vector<int> >& res, int pos) {
	
	res.push_back(sub);

	for (int i=pos; i<nums.size(); i++) {
		sub.push_back(nums[i]);
		backtracking(nums, sub, res, i+1);
		sub.pop_back();
	}
}

vector<vector<int> > subsets(vector<int> &nums) {

	int pos = 0;

	vector<int> sub;
	vector<vector<int> > res;

	backtracking(nums, sub, res, pos);

	return res;
}

int main() {

	vector<int> nums;

	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	// nums.push_back(4);
	// nums.push_back(5);
	// nums.push_back(6);

	vector<vector<int> > response = subsets(nums);

	showVectors(response);

	return 0;
}