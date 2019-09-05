#include "TrieNode.h"
#include <string>
#include <vector>

class Trie {
	
	public:

		Trie() {
			root = new TrieNode();
		}

		void addWord(string word);
		bool findWord(string word);
		vector<string> findWordsWithPrefix(string prefix);
		void deepFirst(TrieNode* node, string word, vector<string> &res);

	private:
		TrieNode* root;	
};

void Trie::addWord(string word) {

	auto aux = root;

	for (int i=0; i<word.length(); i++) {

		if (!aux->next.count(word[i])) {
			aux->next[word[i]] = new TrieNode();
		}

		aux = aux->next[word[i]];
	}

	aux->isTerminal = true;
}


bool Trie::findWord(string word) {

	auto aux = root;

	for (int i=0; i<word.length(); i++)	{

		if (!aux->next.count(word[i])) 
			return false;

		aux = aux->next[word[i]];
	}	

	return aux->isTerminal;
}

vector<string> Trie::findWordsWithPrefix(string prefix) {

	auto aux = root;
	vector<string> res;

	for (int i=0; i<prefix.length(); i++) {

		if (!aux->next.count(prefix[i])) 
			return res;

		aux = aux->next[prefix[i]];
	}

	deepFirst(aux, prefix, res);
	return res;
}

void Trie::deepFirst(TrieNode* node, string word, vector<string> &res) {

	if (node->isTerminal)
		res.push_back(word);

	for (auto n : node->next) {

		char letter = n.first;
		auto aux = n.second;
		deepFirst(aux, word+letter, res); 
	}
}