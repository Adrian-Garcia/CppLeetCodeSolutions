#include <iostream>
#include <vector>
#include <map>

using namespace std;

int sockMerchant(int n, vector<int> ar) {

	map<int, int> myMap;
	map<int, int>::iterator it;
	int count = 0;

	for (int i=0; i<ar.size(); i++) {
		
		it = myMap.find(ar[i]);

		if (it == myMap.end())
			myMap.insert(pair<int, int> (ar[i], 1));

		else 
			it->second++;
	}

	for (it=myMap.begin(); it!=myMap.end(); it++)
		if (it->second >= 2)
			count += it->second/2;

	return count;
}

int main() {
	
	vector<int> ar;

	ar.push_back(10);
	ar.push_back(20);
	ar.push_back(20);
	ar.push_back(10);
	ar.push_back(10);
	ar.push_back(30);
	ar.push_back(50);
	ar.push_back(10);
	ar.push_back(20);

	cout << sockMerchant(ar.size(), ar) << endl;

	return 0;
}