// Date   : 2016.08.06
// Author : yqtao
// https://github.com/yqtaowhu

/*************************************************************************************** 
 *
 * Write a function that takes a string as input and returns the string reversed.
 * 
 * Example:
 * Given s = "hello", return "olleh".
 ***************************************************************************************/

class Solution {
public:
    string reverseString(string s) {
        int len=s.length();
        for(int i=0;i<len/2;i++)
           swap(s[i],s[len-1-i]);
        return s;
    }
};