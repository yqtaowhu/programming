// Date   : 2016.09.26
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Follow up for "Find Minimum in Rotated Sorted Array":
* What if duplicates are allowed?
* 
* Would this affect the run-time complexity? How and why?
* 
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* 
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* 
* Find the minimum element.
* 
* The array may contain duplicates.
*               
**********************************************************************************/
//binary_search
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<high) {
            int mid=(low+high)>>1;
            if(nums[mid]>nums[high]) low=mid+1;
            else if(nums[mid]<nums[high]) high=mid;
            else high--;     //dont know the min ,just let high--
        }
        return nums[low];
    }
};
