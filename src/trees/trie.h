#include <iostream>

struct TrieNode {
	std::vector<TrieNode* > characters;
	bool flag;
};

class Trie {
	private:
		TrieNode *root;
	public:
		Trie () {
			this->root = new TrieNode();
			this->root->characters.resize(26);
			this->root->flag = false;
		}
		
		void insert(std::string word) {
			
			TrieNode *node = this->root;
			for (auto &c : word) {
				if (node->characters[c-'a'] == nullptr) {
					TrieNode *t = new TrieNode();
					t->characters.resize(26);
					t->flag = false;
					node->characters[c-'a'] = t;
				}
				node = node->characters[c-'a'];
			}
			node->flag = true;
		}
		
		bool search(std::string word, bool checkForPrefix = false) {
			
			TrieNode *node = root;
			for (auto &c : word) {
				if (node->characters[c-'a'] == nullptr) {
					return false;
				}
				node = node->characters[c-'a'];
			}
			
			return checkForPrefix ? true : node->flag;
		}
		
		bool startsWith(std::string prefix) {
			return this->search(prefix, true);
		}
};
