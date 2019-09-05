#include "Trie.h"

int main() {
	
	Trie trie;

	trie.addWord("Fernanda");
	trie.addWord("Fertul");
	trie.addWord("Fer Manzanita");
	trie.addWord("Feraligatr");


	if (trie.findWord("Fernanda")) 
		cout << "Yes" << endl;

	else 
		cout << "No" << endl;

	vector<string> res = trie.findWordsWithPrefix("Fer");

	cout << endl;
	for (int i=0; i<res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}