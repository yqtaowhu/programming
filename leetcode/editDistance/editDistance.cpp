// Date   : 2016.08.29
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given two words word1 and word2, find the minimum number of steps required to 
* convert word1 to word2. (each operation is counted as 1 step.)
* 
* You have the following 3 operations permitted on a word:
* 
* a) Insert a character
* b) Delete a character
* c) Replace a character
* 
*               
**********************************************************************************/
//using dp solution
//if word[i]=word[j] dp[i][j]=dp[i-1][j-1]
//else  dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for (int i=0;i<=n1;i++) dp[i][0]=i;
        for (int i=0;i<=n2;i++) dp[0][i]=i;
        for (int i=1;i<=n1;i++) {
            for (int j=1;j<=n2;j++) {
                if (word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
            }
        }
        return dp[n1][n2];
    }
};
