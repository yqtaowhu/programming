// Date   : 2016.08.13
// Author : yqtao
// https://github.com/yqtaowhu
// reference：https://discuss.leetcode.com/topic/15265/0ms-5-lines-dp-solution-in-c-with-explanations

/********************************************************************************** 
 * 
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot is trying to reach 
 * the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *    
 *    
 *    start                                                  
 *    +---------+----+----+----+----+----+                   
 *    |----|    |    |    |    |    |    |                   
 *    |----|    |    |    |    |    |    |                   
 *    +----------------------------------+                   
 *    |    |    |    |    |    |    |    |                   
 *    |    |    |    |    |    |    |    |                   
 *    +----------------------------------+                   
 *    |    |    |    |    |    |    |----|                   
 *    |    |    |    |    |    |    |----|                   
 *    +----+----+----+----+----+---------+                   
 *                                   finish                  
 *    
 * 
 * How many possible unique paths are there?
 * 
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 *               
 **********************************************************************************/
 
//dp solution
class Solution {
public:
     int uniquePaths(int m, int n) {
        vector<vector<int> > path(m, vector<int> (n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                path[i][j] = path[i - 1][j] + path[i][j - 1];
        return path[m - 1][n - 1];
    }
};
//optimize
class Solution {
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m); 
        vector<int> pre(m, 1);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++) {
            for (int i = 1; i < m; i++)
                cur[i] = cur[i - 1] + pre[i];
            swap(pre, cur);
        }
        return pre[m - 1];
    }
};
//optimize
class Solution {
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++)
            for (int i = 1; i < m; i++)
                cur[i] += cur[i - 1]; 
        return cur[m - 1];
    }
}; 