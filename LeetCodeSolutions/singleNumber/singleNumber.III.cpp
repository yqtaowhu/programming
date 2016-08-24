// Date   : 2016.08.24
// Author : yqtao
// https://github.com/yqtaowhu

/*************************************************************************************** 
 *
 * Given an array of numbers nums, in which exactly two elements appear only once and 
 * all the other elements appear exactly twice. Find the two elements that appear only 
 * once.
 * 
 * For example:
 * 
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 * 
 * Note:
 * 
 * The order of the result is not important. So in the above example, [5, 3] is also 
 * correct.
 * Your algorithm should run in linear runtime complexity. Could you implement it using 
 * only constant space complexity?
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 ***************************************************************************************/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int allxor = 0;
        for (int n : nums) {
            allxor ^= n;
        }
        int mask = 1;
        while ( (mask & allxor) == 0 ) {
            mask <<= 1;
        }

        int zero = 0;
        int one = 0;
        for (int n : nums) {
            if (n & mask ){
                one ^= n;
            }else {
                zero ^= n;
            }
        }
        
        vector<int> result;
        result.push_back(zero);
        result.push_back(one);
        return result;
    }
};
