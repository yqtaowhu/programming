// Date   : 2016.08.27
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
* 
* Each element in the array represents your maximum jump length at that position. 
* 
* Determine if you are able to reach the last index.
* 
* For example:
* A = [2,3,1,1,4], return true.
* 
* A = [3,2,1,0,4], return false.
* 
*               
**********************************************************************************/
//only pass one time ,get the maxreach 
class Solution {
public:
    bool canJump(vector<int>& nums) {
         int n=nums.size(),maxreach=0;
         for (int i=0; i < n && i <= maxreach && maxreach < n - 1; ++i)
            maxreach = max(maxreach,i+nums[i]);
         return maxreach>=n-1;
    }
};
