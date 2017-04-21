// Date   : 2016.10.25
// Author : yqtao
// https://github.com/yqtaowhu

/*************************************************************************************** 
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is the 
 * array's size.
 * 
 ***************************************************************************************/
//using priority_queue to solve 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        if (n==0||k<=0||k>n) return vector<int>();
        unordered_map<int,int> map;
        for (int i=0;i<nums.size();i++)
            map[nums[i]]++;
        priority_queue<pair<int,int>> que;
        auto it=map.begin();
        for(;it!=map.end();it++) 
            que.push(make_pair(it->second,it->first));
        vector<int>res;
        while (res.size()<k) {
            res.push_back(que.top().second);
            que.pop();
        }
        return res;
    }
};
