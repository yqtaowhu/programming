// Author : yqtao
// Date   : 2016-09-15
// Email  : yqtao@whu.edu.cn

/********************************************************************************** 
* 
* Given a set of distinct integers, S, return all possible subsets.
* 
* Note:
* 
* Elements in a subset must be in non-descending order.
* The solution set must not contain duplicate subsets.
* 
* For example,
* If S = [1,2,3], a solution is:
* 
* [
*   [3],
*   [1],
*   [2],
*   [1,2,3],
*   [1,3],
*   [2,3],
*   [1,2],
*   []
* ]
* 
*               
**********************************************************************************/
//backtracing solution
class Solution {
public:
void subsets(vector<int>& nums, vector<int>& tmp, vector<vector<int>>& res, int beg) {
	res.push_back(tmp);
	for (int i = beg; i<nums.size(); i++) {
		tmp.push_back(nums[i]);
		subsets(nums, tmp, res, i + 1);
		tmp.pop_back();
	}
}
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>>res;
	vector<int>tmp;
	subsets(nums, tmp, res, 0);
	return res;
}
};
// reference:https://discuss.leetcode.com/topic/19110/c-recursive-iterative-bit-manipulation-solutions-with-explanations
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs(1, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int n = subs.size();
            for (int j = 0; j < n; j++) {
                subs.push_back(subs[j]); 
                subs.back().push_back(nums[i]);
            }
        }
        return subs;
    }
}; 
