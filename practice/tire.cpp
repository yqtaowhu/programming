//careful where to define this trienode
struct TrieNode {
        bool finish;
        TrieNode* next[26];
        TrieNode() {
            for(int i=0;i<26;++i){
                next[i] = nullptr;
            }
            finish = false;
        }
    };
class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    
    Trie() {
        root = new TrieNode();
		//dont write TrieNode* root = new TrieNode() ,it will lead not define root error
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.size();++i){
            int c = word[i] - 'a';
            if(node->next[c] == nullptr) {
                TrieNode* temp = new TrieNode();
                node->next[c] = temp;
            }
            node = node->next[c];
        }
        node->finish = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.size();++i){
            int c = word[i] - 'a';
            if(node->next[c] == nullptr) {
                return false;
            }
            node = node->next[c];
        }
        return node&&node->finish;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i=0;i<prefix.size();++i){
            int c = prefix[i] - 'a';
            if(node->next[c] == nullptr) {
                return false;
            }
            node = node->next[c];
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
