// Date   : 2016.08.05
// Author : yqtao
// https://github.com/yqtaowhu


/********************************************************************************** 
* 
* Rotate an array of n elements to the right by k steps.
* For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]. 
* 
* Note:
* Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
* 
* Hint:
* Could you do it in-place with O(1) extra space?
* 
* Related problem: Reverse Words in a String II
* 
* Credits:Special thanks to @Freezen for adding this problem and creating all test cases.
*               
**********************************************************************************/
//O(N) TIME,AND O(N)SPACE
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        if (len==0||k<=0) return;
        k=k%len;
        vector<int> v(nums.begin()+len-k,nums.end());
        for (int i=len-1;i>=k;i--) {
            nums[i]=nums[i-k];
        }
        for (int i=0;i<k;i++)
            nums[i]=v[i];
    }
};
//O(N) TIME ,O(1) SPACE
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        if (len==0||k<=0) return;
        k=k%len;
        reverse(nums.begin(),nums.begin()+len-k);
        reverse(nums.begin()+len-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};
//O(1) SPACE
class Solution { 
public:
    void rotate(vector<int>& nums, int k) {
        int start = 0, n = nums.size();
        for (; k %= n; n -= k, start += k)
            for (int i = 0; i < k; i++) 
                swap(nums[start + i], nums[start + n - k + i]);
    }
}; 