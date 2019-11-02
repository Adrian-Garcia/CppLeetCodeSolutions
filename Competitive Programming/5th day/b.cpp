#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	
	int n;
	bool flag;
	
	string s; 
	string t;

	set<char> mySetS;
	set<char> mySetT;
	
	cin >> n;
	 
	for (int i=0; i<n; i++) {
		
		cin >> s >> t;
		
		flag = false;

		for(int j=0; j<s.size(); j++)
			mySetS.insert(s[j]);

		for(int j=0; j<t.size(); j++){
			
			mySetT.insert(t[j]);
			
			if (mySetS.find(t[j]) != mySetS.end())
				flag = true;
		}

		(flag) ?
			cout << "YES" << endl:
			cout << "NO" << endl;
		
		mySetS.clear();
		mySetT.clear();
	}
}