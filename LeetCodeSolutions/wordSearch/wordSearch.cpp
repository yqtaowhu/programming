// Author : yqtao
// Date   : 2016-09-15
// Email  : yqtao@whu.edu.cn

/********************************************************************************** 
* 
* Given a 2D board and a word, find if the word exists in the grid.
* 
* The word can be constructed from letters of sequentially adjacent cell, 
* where "adjacent" cells are those horizontally or vertically neighboring. 
* The same letter cell may not be used more than once.
* 
* For example,
* Given board = 
* 
* [
*   ["ABCE"],
*   ["SFCS"],
*   ["ADEE"]
* ]
* 
* word = "ABCCED", -> returns true,
* word = "SEE", -> returns true,
* word = "ABCB", -> returns false.
* 
*               
**********************************************************************************/
//backtracing
class Solution {
public:
    bool check(vector<vector<char>>& board, string word,int i,int j,int rows,int cols,int k,vector<vector<bool>>& visit) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[k] || visit[i][j] ==true)
            return false;
        if (k==word.size()-1) return true;
        visit[i][j]=true;
        if (check(board,word, i-1,j,rows,cols, k + 1, visit)
                || check(board,word, i,j-1,rows,cols, k + 1, visit)
                || check(board,word, i,j+1,rows,cols, k + 1, visit)
                || check(board,word, i+1,j,rows,cols, k + 1, visit))
            return true;
        visit[i][j] = false;  //backtracing
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        if (m==0||n==0) return false;
        vector<vector<bool>> visit(m,vector<bool>(n,false));
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (check(board,word,i,j,m,n,0,visit))
                    return true;
            }
        }
        return false;
    }
};
