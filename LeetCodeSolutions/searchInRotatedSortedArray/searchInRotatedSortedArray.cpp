// Date   : 2016.09.06
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* 
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* 
* You are given a target value to search. If found in the array return its index, otherwise return -1.
* 
* You may assume no duplicate exists in the array.
*               
**********************************************************************************/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        //find the smallest index
        while (low<high) {
            int mid=(low+high)>>1;
            if (nums[mid]>nums[high]) low=mid+1;
            else high=mid;
        }
        int rot=low;low=0,high=n-1;
        //usualy binary search
        while (low<=high) {
            int mid=(low+high)>>1;
            int realmid=(mid+rot)%n;
            if (nums[realmid]==target) return realmid;
            else if (nums[realmid]>target) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};
