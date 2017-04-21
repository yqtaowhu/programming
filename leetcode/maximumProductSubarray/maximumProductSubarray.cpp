// Date   : 2016.08.16
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Find the contiguous subarray within an array (containing at least one number) 
* which has the largest product.
* 
* For example, given the array [2,3,-2,4],
* the contiguous subarray [2,3] has the largest product = 6.
* 
* More examples:
*   
*   Input: arr[] = {6, -3, -10, 0, 2}
*   Output:   180  // The subarray is {6, -3, -10}
*   
*   Input: arr[] = {-1, -3, -10, 0, 60}
*   Output:   60  // The subarray is {60}
*   
*   Input: arr[] = {-2, -3, 0, -2, -40}
*   Output:   80  // The subarray is {-2, -40}
*               
**********************************************************************************/
class Solution {
public:
   int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        long long curmax = nums[0], curmin = nums[0], res = nums[0];
        for(int i=1; i<nums.size(); ++i){
            long long premax = curmax;
            curmax = max(curmax*nums[i], max(curmin*nums[i], (long long)nums[i]));
            curmin = min(premax*nums[i], min(curmin*nums[i], (long long)nums[i]));
            res = max(res, curmax);
        }
        return int(res);
    }
};
