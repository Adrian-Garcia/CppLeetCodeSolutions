#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

bool isVowel(char letter) {
	return (tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'i' ||tolower(letter) == 'o' || tolower(letter) == 'u') ?
		true : false;
}

int main() {
	
	char superHero1[1000];
	char superHero2[1000];

	int i=0;

	bool flag = true;

	cin >> superHero1 >> superHero2;

	while (superHero1[i] && superHero2[i] && flag) {
		if (isVowel(superHero1[i]) != isVowel(superHero2[i]))
			flag = false;
		i++;
	}

	(flag) ?
		cout << "Yes" << endl:
		cout << "No" << endl;

	return 0;
}