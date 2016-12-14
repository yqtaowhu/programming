// Author : yqtao
// Date   : 2016.12.09
// Email  : yqtao@whu.edu.cn
/**************************************************************************************************************
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those 
horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
*****************************************************************************************************************/
struct TrieNode{
    bool is_end;
    TrieNode *children[26];
	TrieNode() {
		is_end = false;
		memset(children, NULL, sizeof(children));
	}
};
class Trie{
public:
    Trie(){root = new TrieNode(); }
    TrieNode* getRoot(){return root;}
    void addWord(const string& word){
        TrieNode* cur=root;
        for(int i=0; i<word.size(); ++i){
            int index=word[i]-'a';
            if(cur->children[index]==NULL)   
               cur->children[index]=new TrieNode();
            cur=cur->children[index];    
        }
        cur->is_end=true;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        TrieNode* root=trie.getRoot();
        for (int i=0;i<words.size();i++)
            trie.addWord(words[i]);
        set<string> result_set;
        for(int x=0; x<board.size(); ++x)
            for(int y=0; y<board[0].size(); ++y)
                findWords(board, x, y, root, "", result_set);
        vector<string> result;
        for(auto it:result_set)    result.push_back(it);
        return result;        
    }
private:
    void findWords(vector<vector<char>>& board, int x, int y, TrieNode* root, string word, set<string>& result){
        if(x<0||x>=board.size()||y<0||y>=board[0].size() || board[x][y]==' ') return;
        if(root->children[board[x][y]-'a'] != NULL){
            word=word+board[x][y];
            root=root->children[board[x][y]-'a']; 
            if(root->is_end) result.insert(word);
            char c=board[x][y];
            board[x][y]=' ';
            findWords(board, x+1, y, root, word, result);
            findWords(board, x-1, y, root, word, result);
            findWords(board, x, y+1, root, word, result);
            findWords(board, x, y-1, root, word, result);
            board[x][y]=c;        
        }
    }
};