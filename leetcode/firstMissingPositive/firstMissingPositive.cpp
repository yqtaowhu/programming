// Date   : 2016.08.10
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given an unsorted integer array, find the first missing positive integer.
* 
* For example,
* Given [1,2,0] return 3,
* and [3,4,-1,1] return 2.
* 
* Your algorithm should run in O(n) time and uses constant space.
* 
*               
**********************************************************************************/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len=nums.size();
        int l=0,r=len;
        while (l<r) {
            if (nums[l]==l+1) l++;
            else if (nums[l]<=l||nums[l]>r||nums[nums[l]-1]==nums[l]) 
                nums[l]=nums[--r];
            else swap(nums[l],nums[nums[l]-1]);
        }
        return l+1;
    }
};
