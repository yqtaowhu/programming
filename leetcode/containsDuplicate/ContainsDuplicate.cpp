// Date   : 2016.08.03
// Author : yqtao
// https://github.com/yqtaowhu
/********************************************************************************** 
 * 
 * Given an array of integers, find if the array contains any duplicates. 
 * Your function should return true if any value appears at least twice in the array, 
 * and it should return false if every element is distinct.
 *               
 **********************************************************************************/
//solution·1：using hash
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for (int i=0;i<nums.size();i++) {
            if (m.find(nums[i])!=m.end())
                return true;
            m[nums[i]]++;
        }
        return false;
    }
};
//solution·2,only one line;
  return set<int>(nums.begin(), nums.end()).size() < nums.size();