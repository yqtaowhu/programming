// Date   : 2016.09.06
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a sorted array of integers, find the starting and ending position of a given target value.
* 
* Your algorithm's runtime complexity must be in the order of O(log n).
* 
* If the target is not found in the array, return [-1, -1].
* 
* For example,
* Given [5, 7, 7, 8, 8, 10] and target value 8,
* return [3, 4].
* 
*               
**********************************************************************************/
//solution 1
//1. first binary_search find the pos of target
//2. find the pos left and pos right using binary_search
class Solution {
public:
    int binary_search(vector<int>& nums, int low, int high, int key){
        while (low<=high) {
            int mid = low + (high-low)/2;
            if (nums[mid] == key) return mid;
            else if (key > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos = binary_search(nums, 0, nums.size()-1, target);
        vector<int> v;
        int low = -1, high = -1;
        if (pos >=0){
            low = high = pos;
            int l = low;
            do {
                low = l;
                l = binary_search(nums, 0, low - 1, target);
            }while (l>=0);
    
            int h = high;
            do {
                high = h;
                h = binary_search(nums, high + 1, nums.size()-1, target);
            }while (h>=0);
        }
        v.push_back(low);
        v.push_back(high);
        return v;
    }
};
//solution 2:reference:https://discuss.leetcode.com/topic/5891/clean-iterative-solution-with-two-binary-searches-with-explanation/2
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        vector<int>res(2,-1);
        while (i<j) {
            int mid=(i+j)/2;
            if (nums[mid]<target) i=mid+1;
            else j=mid;
        }
        if (nums[i]!=target) return res;
        else res[0]=i;
        j=nums.size()-1;
        while (i<j) {
            int mid=(i+j)/2+1;
            if (nums[mid]>target) j=mid-1;
            else i=mid;
        }
        res[1]=j;
        return res;
    }
};
