/* Kth Largest Element in an Array 			Medium

	Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, 
	not the kth distinct element.

	Example 1:
		Input: [3,2,1,5,6,4] and k = 2
		Output: 5
	
	Example 2:
		Input: [3,2,3,1,2,4,5,5,6] and k = 4
		Output: 4
*/
#include <iostream>
#include <set>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {

	set<int> s;
	set<int>::iterator it;
	int index = 0;

	for (int i=0; i<nums.size(); i++)
		s.insert(nums[i]);

	for (it=s.begin(); it!=s.end; it++, index++)
		if (index == k)
			return *it;

	return *it;	
}

int main() {



	return 0;
}