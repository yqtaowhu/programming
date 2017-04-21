// Date   : 2016.09.26
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters. 
 * 
 * The input string does not contain leading or trailing spaces and the words are always separated by a single space. 
 * 
 * For example,
 *  Given s = "the sky is blue",
 *  return "blue is sky the". 
 * 
 * Could you do it in-place without allocating extra space? 
 * 
 * 
 **********************************************************************************/
//easy ,but i have dont buy this ,so i can not sure to AC
class Solution {
public:
    string ReverseSentence(string str) {
        int start=0,end=0;
        for (int i=0;i<=str.size();i++) {
            if (i==str.size()||str[i]==' ') {
                end=i-1;
                while (start<end) {
                    swap(str[start++],str[end--]);
                }
                start=i+1;
            }
             
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
