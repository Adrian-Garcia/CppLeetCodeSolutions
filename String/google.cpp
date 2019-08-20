#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void getVal(vector<int> &values, queue<char> &q) {

	char small = 'z';
	values.push_back(small);
	int index = values.size()-1;
	int mult = 2;

	while (!q.empty()) {

		if (q.front() == small) {
			values[index]*=mult;
			mult++;
		}

		if (q.front() < small) {
			small = q.front();
			values[index] = small;
			mult = 2;
		}

		q.pop();
	}
}

vector<int> solution(string A, string B) {

	vector<int> res;
	vector<int> valuesA;
	vector<int> valuesB;

	queue<char> q;

	for (int i=0; i<A.length(); i++) {

		if (A[i] != ',')
			q.push(A[i]);

		else {

			if (q.empty()) 
				valuesA.push_back(0);

			else
				getVal(valuesA, q);
		}
	}

	getVal(valuesA,q);

	for (int i=0; i<B.length(); i++) {

		if (B[i] != ',')
			q.push(B[i]);

		else {
			
			if (q.empty()) 
				valuesB.push_back(0);

			else
				getVal(valuesB, q);
		}
	}

	getVal(valuesB, q);

	for (int i=0; i<valuesB.size(); i++) {

		res.push_back(0);

		for (int j=0; j<valuesA.size(); j++) {

			if (valuesB[i] > valuesA[j]) {
				res[i]++;
			}
		}
	}

	return res;
}

int main() {

	string A = "abcd,aabc,,";
	string B = "aaa,aa";

	vector<int> res = solution(A, B);

	for (int i=0; i<res.size(); i++) {
		cout << res[i] << " ";
	}

	return 0;
}