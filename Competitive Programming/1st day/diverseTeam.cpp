#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {

	int n;
	int k;
	int currVal;

	priority_queue<int, vector<int>, greater<int> > reverse;

	map<int, int> team;
	map<int, int>::iterator it;

	cin >> n;
	cin >> k;

	for (int i=0; i<n; i++) {
		
		cin >> currVal;

		if (team.size() < k) {
			it = team.find(currVal);

			if (it == team.end()) {
				team.insert(pair<int, int>(currVal, i+1));
			}
		}
	}

	if (team.size() < k) {
		cout << "NO" << endl;
 		return 0;
	} 

	for (it=team.begin(); it!=team.end(); it++) {
		reverse.push(it->second);
	}

	cout << "YES" << endl;

	while (!reverse.empty()) {

		cout << reverse.top() << " ";
		reverse.pop();
	}

	cout << endl;

	// for (it=team.begin(); it!=team.end(); it++) {
	// 	cout << it->first << " " << it->second << endl;
	// }

	return 0;
}