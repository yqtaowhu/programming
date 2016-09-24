// Date   : 2016.09.24
// Author : yqtao
// https://github.com/yqtaowhu
//reference:https://discuss.leetcode.com/topic/21605/accepted-c-java-o-n-time-o-1-space-easy-solution-with-detail-explanations
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
 vector<int> singleNumber(vector<int>& nums)  {
        // Pass 1 : 
        // Get the XOR of the two numbers we need to find
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // Get its last set bit
        diff &= -diff;          //this is the right 1-bit,equal diff&=~(diff-1).
        // Pass 2 :
        vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
        for (int num : nums) {
            if ((num & diff) == 0) // the bit is not set
                rets[0] ^= num;
            else // the bit is set
                rets[1] ^= num;
        }
        return rets;
    }
};
