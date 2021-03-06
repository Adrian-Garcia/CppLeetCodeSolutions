/*
208. Implement Trie (Prefix Tree)                   Medium

    Implement a trie with insert, search, and startsWith methods.

    Example:

        Trie trie = new Trie();

        trie.insert("apple");
        trie.search("apple");       // returns true
        trie.search("app");         // returns false
        trie.startsWith("app");     // returns true
        trie.insert("app");   
        trie.search("app");         // returns true

    Note:

        You may assume that all inputs are consist of lowercase letters a-z.
        All inputs are guaranteed to be non-empty strings.
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct TrieNode{
    bool end;
    map<char, TrieNode*> next;
    
    TrieNode(): end(false) {}
};

class Trie {
public:

    TrieNode* root = new TrieNode();

    /** Initialize your data structure here. */
    Trie() {

        TrieNode* root;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {

        TrieNode* aux = root;

        for (int i=0; i<word.length(); i++) {

            if (!aux->next.count(word[i])) 
                aux->next[word[i]] = new TrieNode();

            aux = aux->next[word[i]];
        }

        aux->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        TrieNode* aux = root;

        for (int i=0; i<word.length(); i++) {

            if (!aux->next.count(word[i]))
                return false;

            aux = aux->next[word[i]];
        } 

        return aux->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        TrieNode* aux = root;

        for (int i=0; i<prefix.length(); i++) {

            if (!aux->next.count(prefix[i]))
                return false; 

            aux = aux->next[prefix[i]];
        }

        return true;
    }
};

