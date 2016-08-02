// Date   : 2016.08.02
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 * 
 * For example:
 * 
 *     1 -> A
 *     2 -> B
 *     3 -> C
 *     ...
 *     26 -> Z
 *     27 -> AA
 *     28 -> AB 
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
   string convertToTitle(int n) {
    string res;
    char tmp;
    while(n){
        n -= 1;
        tmp = 'A' + n % 26;
        res = tmp + res;
        n /= 26;
    }
    return res;
    }
};
