// Author : yqtao
// Date   : 2016-08-07
// Email  : yqtao@whu.edu.cn

/*************************************************************************************** 
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 *
 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18],
 * The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4.
 * Note that there may be more than one LIS combination, it is only necessary for yo
 * to return the length.
 * 
 * Your algorithm should run in O(n2) complexity.
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 * Credits:
 * Special thanks to @pbrother for adding this problem and creating all test cases.
 *               
 ***************************************************************************************/
//O(NLOGN)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for (int i=0;i<nums.size();i++) {
            if (v.size()==0||v.back()<nums[i])
                v.push_back(nums[i]);
            else {
                int low=0,high=v.size()-1;
                while (low<=high) {
                    int mid=low+(high-low)/2;
                    if (v[mid]<nums[i]) low=mid+1;
                    else  high=mid-1;
                }
                v[low]=nums[i];
            }
        }
        return v.size();
    }
};
