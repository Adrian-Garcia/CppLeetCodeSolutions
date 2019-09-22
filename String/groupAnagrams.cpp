/* 49. Group Anagrams			Medium

	Given an array of strings, group anagrams together.

	Example:

		Input:
			["eat", "tea", "tan", "ate", "nat", "bat"],

		Output:
			[
				["ate","eat","tea"],
				["nat","tan"],
				["bat"]
			]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Word {

	string unorder;
	string ordered;

	Word(string w) : unorder(w), ordered(w) {}
};

bool wordsOrder(Word w1, Word w2) {

	if (w1.ordered < w2.ordered)
		return true;

	return false;
}

vector<vector<string> > groupAnagrams(vector<string>& strs) {

	vector<vector<string> > res;
	vector<Word> words;
	string curr;
	int counter;

	for (int i=0; i<strs.size(); i++)
		words.push_back(Word(strs[i]));

	for (int i=0; i<words.size(); i++)
		sort(words[i].ordered.begin(), words[i].ordered.end());

	sort(words.begin(), words.end(), wordsOrder);

	curr = "asdasdasdasd";
	counter = -1;

	for (int i=0; i<words.size(); i++) {

		if (curr == words[i].ordered) 
			res[counter].push_back(words[i].unorder);

		else {

			curr = words[i].ordered;
			counter++;

			res.push_back(vector<string>());
			res[counter].push_back(words[i].unorder);
		}
	}

	return res;
}

int main() {

	vector<string> strs;

	strs.push_back("eat");
	strs.push_back("tea");
	strs.push_back("tan");
	strs.push_back("ate");
	strs.push_back("nat");
	strs.push_back("bat");

	vector<vector<string> > v = groupAnagrams(strs);

	for (int i=0; i<v.size(); i++) {
		for (int j=0; j<v[i].size(); j++) {
			cout << v[i][j] << " "; 
		} cout << endl;
	}

	return 0;
}
