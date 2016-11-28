// Author : yqtao
// Date   : 2016-7-3
// Email  : yqtao@whu.edu.cn
/******************************************************************************************************************
*Given an array of integers, return indices of the two numbers such that they add up to a specific target.
*
*You may assume that each input would have exactly one solution.
*
*Example:
*Given nums = [2, 7, 11, 15], target = 9,
*
*Because nums[0] + nums[1] = 2 + 7 = 9,
*return [0, 1].
*UPDATE (2016/2/13):
*The return format had been changed to zero-based indices. Please read the above updated description carefully.
*******************************************************************************************************************/
//first solution ,O(N^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n=nums.size();
       vector<int> res;
       for (int i=0;i<n-1;i++) {
           for (int j=i+1;j<n;j++) {
               if (nums[i]+nums[j]==target) {
                   res.push_back(i);
                   res.push_back(j);
                   break;
               }
           }
       }
       return res;
    }
};
//solution 2 : O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n=nums.size();
       vector<int> res;
       unordered_map<int,int> map;
       for (int i=0;i<n;i++) {
           if (map.find(nums[i])==map.end())
              map[target-nums[i]]=i;
           else {
               res.push_back(map[nums[i]]);
               res.push_back(i);
               break;
           }
       }
       return res;
    }
};
