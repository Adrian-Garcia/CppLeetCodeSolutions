#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int total(vector<int> A) {

	int sum = 0;

	for (int i=0; i<A.size(); i++)
		sum += A[i];

	return sum; 
}

int solution(vector<int> A) {

	sort(A.begin(), A.end());
	int middle = total(A)/2;

	for (int i=0; i<A.size(); i++)
		if (A[i] == middle)
			return 0;

	int acum = 0;
	int diff = middle*2;

	for (int i=0; i<A.size(); i++) {

		for (int j=0; j<i+2; j++) 
			acum+=A[j];

		if (acum == middle)
			return 0;

		if (acum < diff)
			diff = acum;
	}	

	return abs(middle*2 - diff);
}

int main() {

	vector<int> process;

	process.push_back(1);
	process.push_back(2);
	process.push_back(3);
	process.push_back(4);
	process.push_back(5);

	cout << solution << endl;

	return 0;
}