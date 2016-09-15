// Date   : 2016.08.01
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a sorted array, remove the duplicates in place such that each element appear 
* only once and return the new length.
* 
* Do not allocate extra space for another array, you must do this in place with constant memory.
* 
* For example,
* Given input array A = [1,1,2],
* 
* Your function should return length = 2, and A is now [1,2].
* 
*               
**********************************************************************************/
//solution 1:using stl is very easy.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        auto cur=nums.begin();
        for (;cur!=nums.end()-1;) {
            auto next=cur+1;
            if (*cur==*next)
                cur=nums.erase(cur);   //注意迭代器会失效
            else ++cur;
        }
        return nums.size();
    }
};
//solution 2: 需要注意的是题目中，仅仅说是容器中前面几个数正确即可，因此我们不必要删除每个数
//仅仅是用后一个数去覆盖前一个重复的数即可。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int id = 1;
        for(int i = 1; i < nums.size(); ++i) 
            if(nums[i] != nums[i-1]) 
                nums[id++] = nums[i];
        return id;
    }
};