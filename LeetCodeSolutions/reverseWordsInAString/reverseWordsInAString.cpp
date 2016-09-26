// Date   : 2016.09.26
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
*Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
* 
*               
**********************************************************************************/
 class Solution {
    public:
        void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int storeIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (storeIndex != 0) s[storeIndex++] = ' ';
                int j = i;
                while (j < s.size() && s[j] != ' ') { s[storeIndex++] = s[j++]; }
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);        //j-i 是单词的长度
                i = j;
            }
        }
        s.erase(s.begin() + storeIndex, s.end());
    }
    };
};