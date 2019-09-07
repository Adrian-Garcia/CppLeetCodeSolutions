/* Num in vector

	Given a vector v, and a number k, find if there is any combination in wich
	numbers in v sum k 

	Example:
		Input: v = [1, 2, 3]	k = 4
		Output: true
*/
#include <iostream>
#include <vector>

using namespace std;

bool findNum(vector<int> v, int k, int i, int sum) {

	if (sum == k)
		return true;

	if (i == -1)
		return false;

	else
		return (findNum(v, k, i-1, v[i]+sum) || findNum(v, k, i-1, sum));
}

bool numInVector(vector<int> v, int k) {

	return findNum(v, k, v.size(), 0);
}

int main() {

	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	(numInVector(v, 4)) ?
		cout << "\nYES" << endl:
		cout << "\nNO" << endl;

	return 0;
}