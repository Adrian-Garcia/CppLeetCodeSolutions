/*
500. Keyboard Row 						Easy

	Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard 
	like the image below.
 
	Example:

		Input: ["Hello", "Alaska", "Dad", "Peace"]
		Output: ["Alaska", "Dad"]
 
	Note:
		You may use one character in the keyboard more than once.
		You may assume the input string will only contain letters of alphabet.
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool validate(vector<char> v, string word) {

	int i

	for ()

	return true;
}

vector<string> findWords(vector<string>& words) {

	bool flag;

	vector<string> res;
	vector<char> first;
	vector<char> second;
	vector<char> third;

	first.push_back('e');
	first.push_back('i');
	first.push_back('o');
	first.push_back('p');
	first.push_back('q');
	first.push_back('r');
	first.push_back('t');
	first.push_back('u');
	first.push_back('w');
	first.push_back('y');

	second.push_back('a');
	second.push_back('d');
	second.push_back('f');
	second.push_back('g');
	second.push_back('h');
	second.push_back('j');
	second.push_back('k');
	second.push_back('l');
	second.push_back('s');

	third.push_back('b');
	third.push_back('c');
	third.push_back('m');
	third.push_back('n');
	third.push_back('v');
	third.push_back('x');
	third.push_back('z');

	for (int i=0; i<words.size(); i++) {
		
		if (words[i].size() <= 0)
			continue;

		if (search(first, words[i]))
			flag = validate(first, words[i]);

		if (search(second, words[i]))
			flag = validate(second, words[i]);

		if (search(third, words[i]))
			flag = validate(third, words[i]);

		if (flag)
			res.push_back(words[i]);
	}
}