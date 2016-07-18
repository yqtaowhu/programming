// Author : yqtao
// Date   : 2016-7-3
// Email  : yqtao@whu.edu.cn
/******************************************************************************************************************
*Given an array of integers, return indices of the two numbers such that they add up to a specific target.
*
*You may assume that each input would have exactly one solution.
*
*Example:
*Given nums = [2, 7, 11, 15], target = 9,
*
*Because nums[0] + nums[1] = 2 + 7 = 9,
*return [0, 1].
*UPDATE (2016/2/13):
*The return format had been changed to zero-based indices. Please read the above updated description carefully.
*******************************************************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> m;     //using hash tabel <value,position>=<key,value>
	vector<int>result;
	for (int i = 0; i<nums.size(); i++)
	{
		if (m.find(nums[i]) == m.end())  // not found the second one
			m[target - nums[i]] = i;
		else
		{
			result.push_back(m[nums[i]]);
			result.push_back(i);
			break;        //You may assume that each input would have exactly one solution
		}
	}
	return result;
}
// test
int main()
{
	vector<int>nums = { 2,7,11,15 };
	int target = 9;
	vector<int>result = twoSum(nums, target);
	for (auto c : result)
		cout << c << " " << endl;
}