// Date   : 2016.10.07
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * Given a range [m, n] where 0 
 * 
 * For example, given the range [5, 7], you should return 4.
 * 
 * Credits:Special thanks to @amrsaqr for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
//reference:https://discuss.leetcode.com/topic/12133/bit-operation-solution-java
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == 0) return 0;
        int moveFactor = 1;
        while(m != n){
            m >>= 1;
            n >>= 1;
            moveFactor <<= 1;
        }
        return m * moveFactor;
    }
};
