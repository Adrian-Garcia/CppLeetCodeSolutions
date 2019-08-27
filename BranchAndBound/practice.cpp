#include <iostream>
#include <vector>

using namespace std;

void subset(vector<int> nums, vector<int> &sub, vector<vector<int> > &res, int pos) {

	res.push_back(sub);

	for (int i=pos; i<nums.size(); i++) {
		sub.push_back(nums[i]);
		subset(nums, sub, res, i+1);
		sub.pop_back();
	}
}

vector<vector<int> > subsets(vector<int> nums) {

	vector<vector<int> > res;
	vector<int> sub;
	int pos = 0;

	subset(nums, sub, res, pos);

	return res;
}

int main() {

	vector<int> nums;

	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	vector<vector<int> > v;
	v = subsets(nums);

	for (int i=0; i<v.size(); i++) {
		for (int j=0; j<v[i].size(); j++) {
			cout << v[i][j] << " ";
		} cout << endl;
	}

	return 0;
}