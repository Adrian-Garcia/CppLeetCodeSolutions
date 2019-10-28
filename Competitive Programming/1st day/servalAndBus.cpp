#include <iostream>

using namespace std;

#define nMax 100
#define tMax 100000

int main() {

	int n, t;
	int time;
	int minVal;
	int minPos;
	int arrives[nMax][2];

	cin >> n >> t;

	for (int i=0; i<n; i++) {

		cin >> arrives[i][0];
		cin >> time;

		arrives[i][1] = arrives[i][0];

		while (arrives[i][1] < t)
			arrives[i][1]+=time;
	}

	minVal = arrives[0][1];
	minPos = 0;

	for (int i=0; i<n; i++) {
		if (arrives[i][1] < minVal) {
			minVal = arrives[i][1];
			minPos = i;
		}
	}
		
	cout << minPos+1 << endl;
}