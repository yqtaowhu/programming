// Author : yqtao
// Date   : 2016-09-10
// Email  : yqtao@whu.edu.cn

/********************************************************************************** 
* 
* The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
* such that no two queens attack each other.
* 
* Given an integer n, return all distinct solutions to the n-queens puzzle.
* 
* Each solution contains a distinct board configuration of the n-queens' placement, 
* where 'Q' and '.' both indicate a queen and an empty space respectively.
* 
* For example,
* There exist two distinct solutions to the 4-queens puzzle:
* 
* [
*  [".Q..",  // Solution 1
*   "...Q",
*   "Q...",
*   "..Q."],
* 
*  ["..Q.",  // Solution 2
*   "Q...",
*   "...Q",
*   ".Q.."]
* ]
* 
*               
**********************************************************************************/
//backtracing solution
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> que(n,string(n,'.'));
        solveQueue(res,que,0,n);
        return res;
    }
private:
    void solveQueue(vector<vector<string>>& res,vector<string>& que,int row,int& n) {
        if (row==n) {
            res.push_back(que);return;
        }
        for (int col=0;col!=n;col++) {
            if (isValid(que,row,col,n)) {
                que[row][col]='Q';
                solveQueue(res,que,row+1,n);
                que[row][col]='.';
            }
        }
    }     
    bool isValid(vector<string>& que,int row,int col,int& n) {
        for (int i=0;i!=row;i++)               //column
            if (que[i][col]=='Q') return false;
        for (int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)  //45
            if (que[i][j]=='Q') return false;
        for (int i=row-1,j=col+1;i>=0&&j<n;i--,j++)   //135
              if (que[i][j]=='Q') return false;
        return true;
        
    }
};

