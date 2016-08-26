// Date   : 2016.08.26
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given an array with n objects colored red, white or blue, sort them so that objects of 
* the same color are adjacent, with the colors in the order red, white and blue.
* 
* Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
* 
* Note:
* You are not suppose to use the library's sort function for this problem.
* 
* Follow up:
*  > A rather straight forward solution is a two-pass algorithm using counting sort.
*  > First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array 
*    with total number of 0's, then 1's and followed by 2's.
*  > Could you come up with an one-pass algorithm using only constant space?
*               
**********************************************************************************/
//pass only 1
class Solution {
public:
    void sortColors(vector<int>& nums) {
       int zero=0,second=nums.size()-1;
       for (int i=0;i<=second;i++) {
           while (nums[i]==2&&i<second) swap(nums[i],nums[second--]);
           while (nums[i]==0&&i>zero) swap(nums[i],nums[zero++]);
       }
    }
};
//count sort,pass 2;
class Solution {
public:
    void sortColors(vector<int>& nums) {
       int t0=0,t1=0,t2=0;
       for (int i=0;i<nums.size();i++) {
           if (nums[i]==0) t0++;
           else if (nums[i]==1) t1++;
           else t2++;
       }
       for (int i=0;i<nums.size();i++) {
           if (t0>0) {
               nums[i]=0;t0--;
            }
            else if (t1>0) {
               nums[i]=1;t1--;
            }
            else  
               nums[i]=2;
            
       }
    }
};

