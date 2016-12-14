// Date   : 2016.08.24
// Author : yqtao
// https://github.com/yqtaowhu
//reference:https://discuss.leetcode.com/topic/11877/detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers
/********************************************************************************** 
* 
* Given an array of integers, every element appears three times except for one. Find that single one.
* 
* Note:
* Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
* 
*               
**********************************************************************************/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1=0,x2=0,mask=0;
        for (auto i:nums) {
            x2^=x1&i;
            x1^=i;
            mask=~(x1&x2);
            x2&=mask;
            x1&=mask;
        }
        return x1;
    }
};
