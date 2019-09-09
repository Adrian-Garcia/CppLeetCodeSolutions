#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getPlaces(map<char, vector<int> > &places, string word) {

	for (int i=0; i<word.length(); i++) {
		if (!places.count(word[i]))
			places[word[i]] = vector<int> (1,i);
		else
			places[word[i]]->second.push_back(i);
	}
}

int anagramNum(map<char, vector<int> > places, string word) {

	string look;

	for (int i=0; i<word.size(); i++) {

		look.push_back(word[i]);
	}
}

vector<int> anagrams(vector<string> words) {

	int anagramNum;
	map<char, vector<int> > places;
	vecotr<int> totalAnagrams;

	for (int i=0; i<words.size(); i++) {

		getPlaces(places, words[i]);
		anagramNum = getAnagrams(places, words[i]);
		totalAnagrams.push_back(anagramNum);
		places.clear();
	}

	return totalAnagrams;
}

int main() {
	
	return 0;
}