// Date   : 2016.08.01
// Author : yqtao
// https://github.com/yqtaowhu


/********************************************************************************** 
* 
* Given an array and a value, remove all instances of that value in place and return the new length.
* 
* The order of elements can be changed. It doesn't matter what you leave beyond the new length.
* 
*               
**********************************************************************************/
//very easy using stl
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (auto it=nums.begin();it!=nums.end();) {  //注意迭代器的后移问题
            if (*it==val) {
                it=nums.erase(it);    //在进行删除数据是一定要注意。。。。
            }
            else
                ++it;
        }
        return nums.size();
    }
};
//another way ,quikly 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int id=0;
       for (int i=0;i<nums.size();i++) {
           if (nums[i]!=val)
              nums[id++]=nums[i];
       }
       return id;
    }
};