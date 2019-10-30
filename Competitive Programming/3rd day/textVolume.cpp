#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int main() {

	unsigned long long int n;
	string s;
	string sub;

	unsigned long long int wordVolume = 0;
	unsigned long long int maxVolume = 0;

	cin >> n;

	while (cin >> sub) {
		s.append(sub);
		s.append(" ");

		if (s.length() >= n)
			break;
	}

	for (int i=0; i<s.length(); i++) {

		if (isupper(s[i]))
			wordVolume++;

		if (s[i] == ' ') {
			maxVolume = max(maxVolume, wordVolume); 
			wordVolume = 0;
		}
	
	}

	maxVolume = max(maxVolume, wordVolume); 
	cout << maxVolume << endl;

	return 0;
}