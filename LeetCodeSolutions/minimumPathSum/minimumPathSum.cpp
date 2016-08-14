// Date   : 2016.08.14
// Author : yqtao
// https://github.com/yqtaowhu


/********************************************************************************** 
* 
* Given a m x n grid filled with non-negative numbers, find a path from top left to 
* bottom right which minimizes the sum of all numbers along its path.
* 
* Note: You can only move either down or right at any point in time.
*               
**********************************************************************************/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,grid[0][0]));
        for (int i=1;i<n;i++)
            dp[0][i]=grid[0][i]+dp[0][i-1];
        for (int j=1;j<m;j++)
            dp[j][0]=grid[j][0]+dp[j-1][0];
        for (int i=1;i<m;i++) {
            for (int j=1;j<n;j++) {
                dp[i][j]=min(dp[i][j-1],dp[i-1][j])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
//optimize
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> pre(m, grid[0][0]);
        vector<int> cur(m, 0);
        for (int i = 1; i < m; i++)
            pre[i] = pre[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++) { 
            cur[0] = pre[0] + grid[0][j]; 
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], pre[i]) + grid[i][j];
            swap(pre, cur); 
        }
        return pre[m - 1];
    }
};
//more optimize
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cur(m, grid[0][0]);
        for (int i = 1; i < m; i++)
            cur[i] = cur[i - 1] + grid[i][0]; 
        for (int j = 1; j < n; j++) {
            cur[0] += grid[0][j]; 
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
        }
        return cur[m - 1];
    }
};
