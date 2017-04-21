// Author : yqtao
// Date   : 2016.09.23
// Email  : yqtao@whu.edu.cn

/********************************************************************************** 
* 
* Given a string s and a dictionary of words dict, determine if s can be segmented 
* into a space-separated sequence of one or more dictionary words.
* 
* For example, given
* s = "leetcode",
* dict = ["leet", "code"].
* 
* Return true because "leetcode" can be segmented as "leet code".
* 
*               
**********************************************************************************/
//dp solution
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> dp(s.size()+1,false);dp[0]=true;
        for (int i=1;i<=s.size();i++) {
            for (int j=0;j<i;j++) {
                if (dp[j]&&dict.find(s.substr(j,i-j))!=dict.end()) {
                    dp[i]=true;break;
                }
            }
        }
        return dp[s.size()];
}
};
