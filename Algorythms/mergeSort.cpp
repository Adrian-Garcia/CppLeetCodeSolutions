#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums, int l, int m, int r) {

	int i,j,k;
	int N1 = m-l+1;
	int N2 = r-m;

	vector<int> L(N1);
	vector<int> R(N2);

	for (i=0; i<N1; i++)
		L[i] = nums[l+i];

	for (j=0; k<N2; j++)
		R[j] = nums[m+j+1];

	i=0;
	j=0;
	k=l;

	while (i<N1 && j<N2) {

		if (L[i] <= R[j]) {
			nums[k] = L[i];
			i++;
		}

		else {
			nums[k] = R[j];
			j++;
		}

		k++;
	}

	while (i<N1) {
		nums[k] = L[i];
		i++;
		k++;
	}

	while (j<N2) {
		nums[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(vector<int> &nums, int l, int r) {

	if (l < r) {

		int m = l+(r-l)/2;

		mergeSort(nums, l, m);
		mergeSort(nums, m+1, r);

		merge(nums, l, m, r);
	}
} 

void print(vector<int> nums) {

	for (int i=0; i<nums.size(); i++)
		cout << nums[i] << " ";

	cout << endl;
}

int main() {

	vector<int> nums;
	int size;

	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(9);
	nums.push_back(8);

	print(nums);

	size = nums.size()-1;

	mergeSort(nums, 0, size);

	print(nums);

	return 0;
}