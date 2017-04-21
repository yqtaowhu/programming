// Date   : 2016.08.08
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * Given an array of n integers where n > 1, nums, return an array output such that 
 * output[i] is equal to the product of all the elements of nums except nums[i].
 * 
 * Solve it without division and in O(n).
 * 
 * For example, given [1,2,3,4], return [24,12,8,6].
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array does not 
 * count as extra space for the purpose of space complexity analysis.)
 *               
 **********************************************************************************/
// The trick is to construct the arrays (in the case for 4 elements)
//{              1,         a[0],    a[0]*a[1],    a[0]*a[1]*a[2],  }
//{ a[1]*a[2]*a[3],    a[2]*a[3],         a[3],                 1,  }
//the second array can be using a num to discribe
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);res[0]=1;
        for (int i=1;i<n;i++) 
            res[i]=res[i-1]*nums[i-1];
        int right=1;
        for (int i=n-1;i>=0;i--) {
            res[i]=res[i]*right;
            right=right*nums[i];
        }
        return res;
    }
};



