#include "TrieNode.h"
#include <string>

using namespace std;

class Trie {
	
	public:

		Trie() {
			root = new TrieNode();
		}

	private:
		TrieNode* root;	
}

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


void Trie::findWord(string word) {

	auto aux = root;

		
}
