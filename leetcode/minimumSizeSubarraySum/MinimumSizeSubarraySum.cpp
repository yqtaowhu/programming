// Date   : 2016.10.09
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * Given an array of n positive integers and a positive integer s, find the minimal length of a subarray 
 * of which the sum ≥ s. If there isn't one, return 0 instead.
 * 
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 * 
 * click to show more practice.
 * 
 * More practice:
 * 
 * If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
//O(N)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), start = 0, sum = 0, minlen = INT_MAX;
        for (int i = 0; i < n; i++) { 
            sum += nums[i]; 
            while (sum >= s) {
                minlen = min(minlen, i - start + 1);
                sum -= nums[start++];
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};
//O(N^2)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n=nums.size(),res=INT_MAX;
        for (int i=0;i<n;i++) {
            int sum=0;
            for (int j=i;j<n;j++) {
                sum+=nums[j];
                if (sum>=s) {
                    if (res>j-i+1)
                       res=j-i+1;
                    break;
                }
            }
        }
        return (res==INT_MAX) ? 0 : res;
    }
};