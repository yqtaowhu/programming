// Date   : 2016.08.03
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * Given an array of integers, find out whether there are two distinct indices i and j 
 * in the array such that the difference between nums[i] and nums[j] is at most t and 
 * the difference between i and j is at most k.
 *               
 **********************************************************************************/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> window; // set is ordered automatically 
    for (int i = 0; i < nums.size(); i++) {
        if (i > k) window.erase(nums[i-k-1]); // keep the set contains nums i j at most k
        // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
        auto pos = window.lower_bound(nums[i] - t); // x-nums[i] >= -t ==> x >= nums[i]-t 
        // x - nums[i] <= t ==> |x - nums[i]| <= t    
        if (pos != window.end() && *pos - nums[i] <= t) return true;
        window.insert(nums[i]);
    }
    return false;
}
};