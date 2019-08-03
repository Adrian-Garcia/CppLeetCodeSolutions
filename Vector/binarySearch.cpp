#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> v) {

	for (int i=0; i<v.size(); i++) 
		cout << v[i] << " ";

	cout << endl;
}

int binarySearch(vector<int> &v, int val) {

	int low = 0;
	int mid;
	int big = v.size()-1;

	while (low <= big) {

		mid = (low+big)/2;

		if (v[mid] == val)
			return mid;

		else if (v[mid] > val)
			big = mid-1;

		else 
			low = mid+1;
	}

	v.insert(v.begin() + mid+1, val);

	print(v);

	return mid;
}


int main() {

	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);

	print(v);
	cout << binarySearch(v, 3) << endl << endl;

	cout << binarySearch(v, 9) << endl;

	return 0;
}