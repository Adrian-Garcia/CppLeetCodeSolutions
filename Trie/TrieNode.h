#include <iostream>
#include <map>

class TrieNode {
	public:
		
		TrieNode() {
			isTerminal = false;
		}

		map<char TrieNode*> next;
		bool isTerminal;
}
