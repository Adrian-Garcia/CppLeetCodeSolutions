#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

bool search(long long int r) {

	bool found = false;

	set<char> s;
	set<char>::iterator it;

	ostringstream convert;
	convert << r;

	string num = convert.str();

	cout << endl << endl << num << endl << endl;

	for (int i=0; i<num.length() && !found; i++) {
		
		it = s.find(num[i]);

		if (it == s.end())
			s.insert(num[i]);

		else
			found = true;
	}

	it = s.find(num[num.size()-1]);

	if (it != s.end())
		found = false;

	return !found;
}

int main() {

	long long int l;
	long long int r;

	long long int i;

	bool flag = false;

	cin >> l >> r;

	for (i=l; i<=r && !flag; i++) {
		flag = search(r);
	}


	if (flag)
		cout << i << endl;

	else
		cout << -1 << endl;

	return 0;
}