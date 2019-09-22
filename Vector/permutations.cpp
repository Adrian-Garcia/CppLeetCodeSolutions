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
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > permute(vector<int>& nums) {

	vector<vector<int> > permutations;
	sort(nums.end(), nums.begin());

	do {
		permutations.push_back(nums);
	} while (next_permutation(nums.begin(), nums.end()));        

	return permutations;
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