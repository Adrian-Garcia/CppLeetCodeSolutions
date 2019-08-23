#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &nums, int val) {

	int low = 0;
	int big = nums.size()-1;
	int mid;

	while (low <= big) {

		mid = (low+big)/2;

		if (nums[mid] == val) 
			return mid;

		else if (nums[mid] > val)
			big = mid-1;

		else
			low = mid+1;
	}

	return mid;
}

void insertion(vector<int> &nums, int val, int pos) {
	
	nums.insert(nums.begin() + pos, val);
}

int main() {


	vector<int> nums;

	int pos, val;

	val = 1;
	pos = binarySearch(nums, val);
	insertion(nums, val, pos);

	val = 2;
	pos = binarySearch(nums, val);
	insertion(nums, val, pos);

	val = 4;
	pos = binarySearch(nums, val);
	insertion(nums, val, pos);

	val = 1;
	pos = binarySearch(nums, val);
	insertion(nums, val, pos);

	val = 5;
	pos = binarySearch(nums, val);
	insertion(nums, val, pos);

	for (int i=0; i<nums.size(); i++) {
		cout << nums[i] << " ";
	}

}