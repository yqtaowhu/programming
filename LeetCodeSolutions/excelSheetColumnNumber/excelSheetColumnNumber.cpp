// Date   : 2016.08.02
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * Related to question Excel Sheet Column Title
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 * 
 * For example:
 *     A -> 1
 *     B -> 2
 *     C -> 3
 *     ...
 *     Z -> 26
 *     AA -> 27
 *     AB -> 28 
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
//very easy ,just know how to str2int.
//this prob1em is not consider overflow,but it can AC,if consider it also easy.
class Solution {
public:
    int titleToNumber(string s) {
        int res=0,i=0;
        while (s[i]==' ') i++;
        for (;i<s.size()&&s[i]!=' ';i++) {
            int digit=s[i]-'A'+1;
            res=res*26+digit;
        }
        return res;
    }
};