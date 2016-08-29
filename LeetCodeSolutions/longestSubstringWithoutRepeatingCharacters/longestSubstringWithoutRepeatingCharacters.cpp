// Date   : 2016.08.29
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a string, find the length of the longest substring without repeating characters. 
* For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
* which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*               
**********************************************************************************/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size(),maxLen=0,lastRepeatPos=-1;
        map <char,int>m;
        for (int i=0;i<len;i++) {
            if (m.find(s[i])!=m.end()&&lastRepeatPos<m[s[i]])
                lastRepeatPos=m[s[i]];
            maxLen=max(i-lastRepeatPos,maxLen);
            m[s[i]]=i;
        }
        return maxLen;
    }
};
