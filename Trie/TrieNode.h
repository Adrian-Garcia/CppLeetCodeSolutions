#include <iostream>
#include <map>

using namespace std;

class TrieNode {
	public:

		TrieNode() : isTerminal(false) {}

		map<char, TrieNode*> next;
		bool isTerminal;
};