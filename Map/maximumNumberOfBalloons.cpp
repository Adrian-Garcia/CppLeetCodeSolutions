#include <iostream>
#include <limits>
#include <map>

using namespace std;

int maxNumberOfBalloons(string text) {

	int min = INT_MAX;
	vector< <pair<char, int> > balloon;
	map<char, int> mText;

	balloon.push_back(pair<char, int> ('b',1));
	balloon.push_back(pair<char, int> ('a',1));
	balloon.push_back(pair<char, int> ('l',2));
	balloon.push_back(pair<char, int> ('o',2));
	balloon.push_back(pair<char, int> ('n',1));

	map<char, int>::iterator it;

	for (int i=0; i<text.length(); i++) {

		it.find(text[i]);

		if (it != mText.end())
			it->second++;

		else 
			mText.insert(pair<char, int> (text[i], 1));
	}

	for (int i=0; i<balloon.size(); i++) {

		it.find(balloon[i]->first);

		if (it != mText.end()) {

			if (it->second / balloon[i]->second < min) 
				min = it->second / balloon[i]->second;
		}

		else {
			return 0;
		}
	}

	return min;
}

int main() {

	

	return 0;
}