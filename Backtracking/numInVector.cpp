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

void findNum(vector<int> v, int k, int i, int sum, bool &flag) {

	if (flag)
		return;

	if (sum == k)
		flag = true;

	if (i == -1)
		return;

	else
		findNum(v, k, i-1, v[i]+sum, flag); 
		findNum(v, k, i-1, sum, flag);
}

bool numInVector(vector<int> v, int k) {

	bool flag = false;

	findNum(v, k, v.size(), 0, flag);
	
	return flag;
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