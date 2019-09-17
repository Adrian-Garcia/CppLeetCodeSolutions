#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	
	unordered_map<string, int> uMap;

	uMap.insert(pair<string, int> ("Fer", 20));
	uMap.insert(pair<string, int> ("Adrian", 20));
	uMap.insert(pair<string, int> ("Burbuja", 14));
	uMap.insert(pair<string, int> ("Lola", 15));
	uMap.insert(pair<string, int> ("Pepe", 6));

	unordered_map<string, int>::iterator it;

	for (it = uMap.begin(); it != uMap.end(); it++)
		cout << it->first << " " << it->second << endl;
	cout << endl;

	it = uMap.find("Fer");
	(it != uMap.end()) ? 
		cout << "YES" << endl:
		cout << "NO" << endl;

	it->second = 1;
	cout << it->first << " " << it->second << endl;
	
	return 0;
}