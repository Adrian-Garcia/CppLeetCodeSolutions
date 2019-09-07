#include <iostream>
#include <vector>

using namespace std;

int jumpingOnClouds(vector<int> c) {

	int a=0;
	int acum=0;

	for (int i=0; i<c.size(); i++) {

		if (c[i] == 0)
			a++;

		else {
			acum+=a/2;
			acum++;
			a=0;
		}
	}

	return acum;
}

int main() {

	vector<int> c;

	c.push_back(0);
	c.push_back(0);
	c.push_back(1);
	c.push_back(0);
	c.push_back(0);
	c.push_back(1);
	c.push_back(0);

	cout << jumpingOnClouds(c) << endl;

	return 0;
}