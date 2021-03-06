// Date   : 2016.08.02
// Author : yqtao
// https://github.com/yqtaowhu
/********************************************************************************** 
 * 
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always exist in the array.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
class Solution {
public:
       int majorityElement(vector<int>& nums) {
        int major, counts = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!counts) {
                major = nums[i];
                counts = 1;
            }
            else counts += (nums[i] == major) ? 1 : -1;
        }
        return major;
    }
};
//
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int x=0,cx=0;
       for (auto c:nums) {
           if (x==c) cx++;      
           else if (!cx) x=c,cx=1;
           else --cx;
       }
       cx=0;
       for (auto c:nums)          //检验正确性。
           if(x==c) cx++;
       return cx>nums.size()/2 ? x : -1;
    }
};
//using hashtable 
class Solution {
public:
     int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts; 
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (++counts[nums[i]] > n / 2)
                return nums[i];
        return 0;
    }
};
// sort ，but it O(nlogn)
 int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size() / 2];
    } 