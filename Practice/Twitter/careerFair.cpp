#include <iostream>
#include <vector>

using namespace std;

struct timeLine {

	int companies;
	int end;
	bool flag;
	bool free;

	timeLine(int companies, int end) : flag(false), free(false) {}
};

int maxEvents(vector<int> arrival, vector<int> duration) {

	vector<timeLine> posibilities;
	int maxComp = -1;

	posibilities.push_back(timeLine(1, arrival[0]+duration[0]));

	for (int i=1; i<arrival.size(); i++) {

		for (int j=0; j<posibilities.size(); j++) {

			// Timeline is free
			if (posibilities[j].free) {
				posibilities[j].end = arrival[i]+duration[i];
				posibilities[j].free = false;
			}

			// Check is timeline is going to be free
			else if (posibilities[j].end <= arrival[i]) {
				posibilities[j]
			}

			// Create a new timeLine
			if (arrival[i] >= posibilities[j].end && !posibilities[j].flag) {
				posibilities.push_back(timeLine(posibilities[j].companies-1, arrival[i]+duration[i]));
				posibilities[j].flag = true;
			}

			// else if (arrival[i] >= posibilities[j].end) {
			// 	posibilities[j].end = arrival[i] + duration[i];
			// 	posibilities[j].flag = false;
			// }

			// current timeLine is free
			else {
				posibilities[j].end = arrival[i] + duration[i];
				posibilities[j].companies++;
				posibilities[j].flag = false;
			}
		}
	}

	for (int i=0; i<posibilities.size(); i++)
		maxComp = max(maxComp, posibilities[i].companies);

	posibilities.clear();

	return maxComp;
}

int main() {

	vector<int> arrival;
	vector<int> duration;

	arrival.push_back(1);
	arrival.push_back(3);
	arrival.push_back(3);
	arrival.push_back(5);
	arrival.push_back(7);

	duration.push_back(2);
	duration.push_back(2);
	duration.push_back(1);
	duration.push_back(2);
	duration.push_back(1);

	cout << maxEvents(arrival, duration) << endl;

	return 0;
}