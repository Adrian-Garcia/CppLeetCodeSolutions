#include <iostream>
#include <string>
#include <set>

using namespace std;

bool compare(string s, string t) {

	set<char> mySet;
	set<char>::iterator it; 

	bool flag = false;

	for (int i=0; i<s.length(); i++)
		mySet.insert(s[i]);

	for (int i=0; i<t.length() && !flag; i++) {

		it = mySet.find(t[i]);

		if (it != mySet.end())
			flag = true;
	}

	return flag;
}

int main() {

	int n;

	string s;
	string t;

	cin >> n;

	for (int i=0; i<n; i++) {

		cin >> s >> t;

		(compare(s, t)) ?
			cout << "YES" << endl:
			cout << "NO" << endl;
	}

	return 0;
}