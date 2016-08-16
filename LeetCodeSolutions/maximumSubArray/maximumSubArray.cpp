// Date   : 2016.08.16
// Author : yqtao
// https://github.com/yqtaowhu
/********************************************************************************** 
* 
* Find the contiguous subarray within an array (containing at least one number) 
* which has the largest sum.
* 
* For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
* the contiguous subarray [4,−1,2,1] has the largest sum = 6.
* 
* More practice:
* 
* If you have figured out the O(n) solution, try coding another solution using 
* the divide and conquer approach, which is more subtle.
* 
*               
**********************************************************************************/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,res=INT_MIN;
        for (int i=0;i<nums.size();i++) {
            sum+=nums[i];
            res=max(res,sum);
            if (sum<0) sum=0;
            
        }
        return res;
    }
};
