// Date   : 2016.08.25
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * 
 *               
 **********************************************************************************/
class TrieNode {
public:
	// Initialize your data structure here.
	bool isWord;
	TrieNode *next[26];
	TrieNode() {
		isWord = false;
		memset(next, NULL, sizeof(next));
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode* location = root;
		for (int i = 0; i<word.size(); i++) {
			if (location->next[word[i] - 'a'] == NULL) {
				TrieNode * temp = new TrieNode();
				location->next[word[i] - 'a'] = temp;
			}
			location = location->next[word[i] - 'a'];
		}
		location->isWord = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* location = root;
		for (int i = 0; i<word.size() && location; i++) {
			location = location->next[word[i] - 'a'];
		}
		return location&&location->isWord;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode* location = root;
		for (int i = 0; i<prefix.size() && location; i++) {
			location = location->next[prefix[i] - 'a'];
		}
		return location;
	}
private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
