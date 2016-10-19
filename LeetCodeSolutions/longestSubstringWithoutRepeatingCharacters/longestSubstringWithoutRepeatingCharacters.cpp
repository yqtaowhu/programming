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
// a esay way
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int beg=0,end=0,counter=0,count=0;
        while (end<s.size()) {
            if (m[s[end++]]++>0) counter++;
            while (counter>0) 
                if (m[s[beg++]]-->1) counter--;
            count=max(count,end-beg);
        }
        return count;
    }
};