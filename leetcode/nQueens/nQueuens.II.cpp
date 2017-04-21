// Author : yqtao
// Date   : 2016-09-10
// Email  : yqtao@whu.edu.cn

/********************************************************************************** 
* 
* Follow up for N-Queens problem.
* 
* Now, instead outputting board configurations, return the total number of distinct solutions.
* 
*               
**********************************************************************************/
//backtracing solutions
class Solution {
public:
    int totalNQueens(int n) {
        int res=0;
        vector<string> que(n,string(n,'.'));
        solveQueue(res,que,0,n);
        return res;
    }
    void solveQueue(int& res,vector<string>& que,int row,int& n) {
        if (row==n) {
            res++;return;
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

