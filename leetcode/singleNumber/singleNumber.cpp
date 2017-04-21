// Date   : 2016.08.23
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given an array of integers, every element appears twice except for one. Find that single one.
* 
* Note:
* Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
* 
*               
**********************************************************************************/
//using xor is very easy
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for (int i=0;i<nums.size();i++)
            res^=nums[i];
        return res;
    }
};
