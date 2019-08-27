#include <iostream>
#include <set>

using namespace std;

int main() {

	set<int> mySet;

	mySet.insert(2);
	mySet.insert(3);
	mySet.insert(10);
	mySet.insert(1);
	mySet.insert(4);
	mySet.insert(2);

	set<int>::iterator it = mySet.find(3);

	if (it != mySet.end())
		cout << "YES";
	else
		cout << "NO";

	cout << endl << endl;

	for (it = mySet.begin(); it != mySet.end(); it++) 
        cout << *it << " "; 

	return 0;
}