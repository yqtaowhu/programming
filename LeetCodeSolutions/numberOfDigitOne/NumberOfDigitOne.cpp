// Author : yqtao
// Date   : 2016-09-12
// Email  : yqtao@whu.edu.cn

/********************************************************************************** 
 * 
 * Given an integer n, count the total number of digit 1 appearing in all non-negative 
 * integers less than or equal to n.
 * 
 * For example: 
 * Given n = 13,
 * Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 * 
 *   Beware of overflow.
 * 
 **********************************************************************************/
 //reference:https://discuss.leetcode.com/topic/18054/4-lines-o-log-n-c-java-python
class Solution {
public:
    int countDigitOne(int n) {
        int ones = 0;
        for (long long m = 1; m <= n; m *= 10) {
             int a = n/m, b = n%m;
             ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
        }
        return ones;
}
};