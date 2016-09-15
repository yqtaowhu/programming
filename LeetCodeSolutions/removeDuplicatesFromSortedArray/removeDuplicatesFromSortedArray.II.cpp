// Date   : 2016.08.01
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Follow up for "Remove Duplicates":
* What if duplicates are allowed at most twice?
* 
* For example,
* Given sorted array A = [1,1,1,2,2,3],
* 
* Your function should return length = 5, and A is now [1,1,2,2,3].
* 
*               
**********************************************************************************/
//reference:https://discuss.leetcode.com/topic/17180/3-6-easy-lines-c-java-python-ruby
class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}
};

