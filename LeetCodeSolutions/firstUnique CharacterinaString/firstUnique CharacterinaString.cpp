// Author : yqtao
// Date   : 2016-09-09
// Email  : yqtao@whu.edu.cn
/************************************************************************************
*Given a string, find the first non-repeating character in it and return it's index. 
*If it doesn't exist, return -1.
*
*Examples:
*
*s = "leetcode"
*return 0.
*
*s = "loveleetcode",
*return 2.
**********************************************************************************************/
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> map(26,0);
        for (auto c:s)
            map[c-'a']++;
        for (int i=0;i<s.size();i++)
            if (map[s[i]-'a']==1) return i;
        return -1;
    }
};