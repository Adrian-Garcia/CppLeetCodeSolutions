#include <iostream>
#include <vector>

using namespace std;

struct timeLine {

	int companies;
	int end;

	timeLine(int end) companies(0), : {}
};

int maxEvents(vector<int> arrival, vector<int> duration) {

	vector<timeLine> posibilities;

	timeLine pos(arrival[0]+duration[0]);
	pos.companies++;

	for (int i=1; i<arrival.size(); i++) {

		for (int j=0; j<posibilities.size(); j++) {

			if (arrival[i] >= ) {
				
			}
		}
	}
}

int main() {



	return 0;
}