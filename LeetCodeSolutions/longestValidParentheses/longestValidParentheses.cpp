// Date   : 2016.09.06
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a string containing just the characters '(' and ')', 
* find the length of the longest valid (well-formed) parentheses substring.
* 
* For "(()", the longest valid parentheses substring is "()", which has length = 2.
* 
* Another example is ")()())", where the longest valid parentheses substring is "()()", 
* which has length = 4.
* 
*               
**********************************************************************************/
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(),maxLen=0;
        if (n<2) return 0;
        stack<int> st;
        for (int i=0;i<n;i++) {
            if (s[i]=='(') st.push(i);
            else {
                if (st.empty()) st.push(i);
                else {
                    if (s[st.top()]=='(') {
                        st.pop();
                        maxLen=max(maxLen,i-(st.empty()? -1:st.top()));
                    }
                    else st.push(i);
                }
            }
        }
        return maxLen;
    }
};
