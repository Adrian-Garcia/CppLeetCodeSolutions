/*
520. Detect capital 		Easy

	We define the usage of capitals in a word to be right when one of the following cases holds:

	All letters in this word are capitals, like "USA".
	All letters in this word are not capitals, like "leetcode".
	Only the first letter in this word is capital, like "Google".
	Otherwise, we define that this word doesn't use capitals in a right way.

Example 1:
	Input: "USA"
	Output: True
 

Example 2:
	Input: "FlaG"
	Output: False
*/

#include <iostream>
#include <string>

using namespace std;

bool lower(string word) {

	int n = word.length();
	bool flag = true;

	for (int i=0; i<n && flag; i++) 
		if (isupper(word[i])) 
			flag = false;

	return flag;	
}

bool fullupper(string word) {

	int n = word.length();
	bool flag = true;

	for (int i=0; i<n && flag; i++) 
		if (islower(word[i])) 
			flag = false;

	return flag;
}

bool upper(string word) {

	int n = word.length();
	bool flag = true;

	if (n == 1)
		return true;


	for (int i=1; i<n && flag; i++) 
		if (isupper(word[i])) 
			flag = false;

	return flag;
}

bool detectCapitalUse(string word) {

	bool flag = false;
	int counter = 0;
	int i=0;

	while (word[i] == ' ') {
		flag = true;
		counter++;
		i++;
	}

	if (flag)
		word.erase(0,counter);

	if (word.length() >= 2) {
		cout << "1" << endl;
		if (isupper(word[0]) && isupper(word[1])) {
			flag = fullupper(word);
			cout << "2" << endl;
		}
	}

	if (isupper(word[0])) 
		flag = upper(word);
 	
	if (islower(word[0])) 
		flag = lower(word);

	return flag;
}

int main() {

	string word = "USA";

	(detectCapitalUse(word)) ?
		cout << "Yes" << endl:
		cout << "No"  << endl;

	return 0;
}
