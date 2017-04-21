// Date   : 2016.09.20
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a string S and a string T, count the number of distinct subsequences of T in S.
* 
* A subsequence of a string is a new string which is formed from the original string 
* by deleting some (can be none) of the characters without disturbing the relative positions 
* of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
* 
* Here is an example:
* S = "rabbbit", T = "rabbit"
* 
* Return 3.
* 
*               
**********************************************************************************/
//dp solution
class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.size(),n=t.size();
        if (m<n) return 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for (int i=0;i<=m;i++) dp[0][i]=1;
        for (int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if (t[i-1]==s[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                else dp[i][j]=dp[i][j-1];
            }
        }
        return dp[n][m];        
    }
};
