// Date   : 2016.09.27
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* A peak element is an element that is greater than its neighbors.
* 
* Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
* 
* You may imagine that num[-1] = num[n] = -∞.
* 
* For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
* 
* click to show spoilers.
* 
* Note:
* Your solution should be in logarithmic complexity.
* 
* Credits:Special thanks to @ts for adding this problem and creating all test cases.
*               
**********************************************************************************/
//O(N)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) return -1;
        if (nums.size()==1||nums[0]>nums[1]) return 0;
        if (nums[nums.size()-1]>nums[nums.size()-2]) return nums.size()-1;
        for (int i=1;i<nums.size()-1;i++) 
            if (nums[i]>nums[i-1]&&nums[i]>nums[i+1]) return i;
        return -1;
    }
};
//binary_search
class Solution {
public:
    int findPeakElement(vector<int> &num) {
    int n = num.size();
    int low = 0;
    int high = n - 1;
    while ( low < high ) {
        int mid = low + ( high - low ) / 2;
        if ( ( mid == 0 || num[mid] > num[mid-1] ) && 
                ( mid == n-1 ||  num[mid] > num[mid+1] )  ){
            return mid;
        }
        if (mid >0 && num[mid-1] > num[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
};
