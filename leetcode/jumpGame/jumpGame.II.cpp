// Date   : 2016.08.08
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
* 
* Each element in the array represents your maximum jump length at that position. 
* 
* Your goal is to reach the last index in the minimum number of jumps.
* 
* For example:
* Given array A = [2,3,1,1,4]
* 
* The minimum number of jumps to reach the last index is 2. 
* (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
* 
*               
**********************************************************************************/
class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0, n = nums.size(), step = 0, end = 0, maxend = 0;
        while (end < n - 1) {
        	step++;
            for (;i <= end; i++) {
            	maxend = max(maxend, i + nums[i]);
                if (maxend >= n - 1) return step;
            }
            if(end == maxend) break;
            end = maxend;
        }
        return n == 1 ? 0 : -1;
    }
};
