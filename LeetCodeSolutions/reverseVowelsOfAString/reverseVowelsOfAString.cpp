// Date   : 2016.08.24
// Author : yqtao
// https://github.com/yqtaowhu

/*************************************************************************************** 
 *
 * Write a function that takes a string as input and reverse only the vowels of a 
 * string.
 * 
 * Example 1:
 * Given s = "hello", return "holle".
 * 
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 * 
 ***************************************************************************************/
class Solution {
public:
    bool IsVowel(char c) {
    return (c == 'a') || (c == 'e') || (c == 'o') || (c == 'i') || (c == 'u') ||
           (c == 'A') || (c == 'E') || (c == 'O') || (c == 'I') || (c == 'U') ;
    }
    string reverseVowels(string s)  {
        int n=s.size();
        int i=0,j=n-1;
        while (i<j) {
            while (i<j&&!IsVowel(s[i])) i++;
            while (i<j&&!IsVowel(s[j])) j--;
            swap(s[i],s[j]);
            i++;j--;
        }
        return s;
    }
};