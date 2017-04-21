// Date   : 2016.09.11
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
* return the length of last word in the string.
* 
* If the last word does not exist, return 0.
* 
* Note: A word is defined as a character sequence consists of non-space characters only.
* 
* For example, 
* Given s = "Hello World",
* return 5.
* 
*               
**********************************************************************************/
class Solution {
public:
   int lengthOfLastWord(string s) {
       int i=s.size()-1,len=0;
       while (s[i]==' '&&i>=0) i--;
       while (s[i]!=' '&&i>=0) {
           i--;len++;
       }
       return len;
    }
};
