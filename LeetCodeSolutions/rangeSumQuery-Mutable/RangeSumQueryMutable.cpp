// Date   : 2016.08.13
// Author : yqtao
// https://github.com/yqtaowhu

/*************************************************************************************** 
 *
 * Given an integer array nums, find the sum of the elements between indices i and j (i 
 * ≤ j), inclusive.
 * 
 * The update(i, val) function modifies nums by updating the element at index i to val.
 * 
 * Example:
 * 
 * Given nums = [1, 3, 5]
 * 
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * 
 * Note:
 * 
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is distributed 
 * evenly.
 *
 ***************************************************************************************/
// The idea is fairly straightforward: create an array res that stores the accumulated sum for nums such that 
// res[i] = nums[0] + ... + nums[i - 1] in the initializer of NumArray. Then just return accu[j + 1] - accu[i] in sumRange. 
// You may try the example in the problem statement to convince yourself of this idea.

The code is as follows.
class NumArray {
public:
    NumArray(vector<int> &nums) {
       res.push_back(0);
       for (auto num:nums)
          res.push_back(res.back()+num);
    }

    int sumRange(int i, int j) {
        return res[j+1]-res[i];
    }
    vector<int>res;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
