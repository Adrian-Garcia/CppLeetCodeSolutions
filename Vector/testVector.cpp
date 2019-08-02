#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> v(1,0);

	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 4;
	v[4] = 5;
	v[5] = 6;

	for (int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}