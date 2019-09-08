/* Minimum Swaps 2		(Medium)

	You are given an unordered array consisting of consecutive integers  [1, 2, 3, ..., n] without any 
	duplicates. You are allowed to swap any two elements. You need to find the minimum number of swaps 
	required to sort the array in ascending order.

	For example, given the array arr = [7,1,3,2,4,5,6] we perform the following steps:

		i   arr 					swap (indices)
		0   [7, 1, 3, 2, 4, 5, 6]   swap (0,3)
		1   [2, 1, 3, 7, 4, 5, 6]   swap (0,1)
		2   [1, 2, 3, 7, 4, 5, 6]   swap (3,4)
		3   [1, 2, 3, 4, 7, 5, 6]   swap (4,5)
		4   [1, 2, 3, 4, 5, 7, 6]   swap (5,6)
		5   [1, 2, 3, 4, 5, 6, 7]

		It took 5 swaps to sort the array.

	Function Description

		Complete the function minimumSwaps in the editor below. It must return an integer representing the 
		minimum number of swaps to sort the array.

		minimumSwaps has the following parameter(s):

		arr: an unordered array of integers
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumSwaps(vector<int> arr) {

	if (arr.size() == 0)
		return 0;

	bool flag;
	int min;
	int pos;
	int swaps = 0;

	for (int i=0; i<arr.size(); i++) {

		flag = false;
		min = arr[i];
		pos = i;

		for (int j=i; j<arr.size(); j++) {
			
			if (arr[j] < min) {
				min = arr[j];
				flag = true;
				pos = j;
			}
		}

		if (flag) {
			swap(arr[i], arr[pos]);
			swaps++;
		}
	}

	return swaps;
}

int main() {
	
	vector<int> v;

	v.push_back(4);
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);

	cout << minimumSwaps(v) << endl;

	return 0;
}