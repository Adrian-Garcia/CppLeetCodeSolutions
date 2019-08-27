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
	int big = v.size()-1;
	int mid = (big+low)/2;

	while (low <= big) {

		mid = (big+low)/2;

		if (v[mid] == val)
			return mid;

		else if (v[mid] < val) 
			low = mid+1;

		else
			big = mid-1;
	}

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

	return 0;
}