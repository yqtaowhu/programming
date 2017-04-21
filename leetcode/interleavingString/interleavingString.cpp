// Date   : 2016.09.18
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
* 
* For example,
* Given:
* s1 = "aabcc",
* s2 = "dbbca",
* 
* When s3 = "aadbbcbcac", return true.
* When s3 = "aadbbbaccc", return false.
* 
*               
**********************************************************************************/
//dp solution
class Solution {
public:
     bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(),n=s2.size(),o=s3.size();
        if (m+n!=o) return false;
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for (int i=1;i<=m;i++) dp[i][0]=(dp[i-1][0]&&s3[i+0-1]==s1[i-1]); 
        for (int j=1;j<=n;j++) dp[0][j]=(dp[0][j-1]&&s3[0+j-1]==s2[j-1]);
        for (int i=1;i<=m;i++) 
            for (int j=1;j<=n;j++) 
                dp[i][j]=(dp[i-1][j]&&s3[i+j-1]==s1[i-1])||(dp[i][j-1]&&s2[j-1]==s3[i+j-1]);
        return dp[m][n];
}
};
