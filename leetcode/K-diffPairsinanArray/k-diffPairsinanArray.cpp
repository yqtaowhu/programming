/********************************************************************************************************************
Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array.
 Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.

Example 1:
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:
Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:
Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
******************************************************************************************************/
//直接将满足的结果扔进set中，这样最简单，注意set的使用，非常的重要
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size()<2) return 0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<pair<int,int>>st;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++) {
                if(nums[j]-nums[i]==k){
                    st.insert({nums[i],nums[j]});
                }
                
            }
        }
        return st.size();
    }
};
//O(N),分情况讨论，如成k为0和不为0的两种情况
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); ++i)
           ++m[nums[i]];
        int res = 0;
        if(k != 0) {
            for(auto it = m.begin(); it != m.end(); ++it)
               if(m.find(it->first+k) != m.end())
                   ++res;
        } else {
            for(auto it = m.begin(); it != m.end(); ++it)
               if(it->second > 1)
                   ++res;
        }
        return res;
    }
};