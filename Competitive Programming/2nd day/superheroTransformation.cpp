#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

bool isVowel(char letter) {
	return (tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'i' ||tolower(letter) == 'o' || tolower(letter) == 'u') ?
		true : false;
}

int main() {
	
	string superHero1;
	string superHero2;

	int i=0;
	int j=0;

	bool flag = true;

	cin >> superHero1 >> superHero2;

	if (superHero1.length() != superHero2.length()) 
		flag = false;

	while (superHero1[i] && superHero2[j] && flag) {
		if (isVowel(superHero1[i]) != isVowel(superHero2[i]))
			flag = false;
		i++;
	}

	(flag) ?
		cout << "Yes" << endl:
		cout << "No" << endl;

	return 0;
}