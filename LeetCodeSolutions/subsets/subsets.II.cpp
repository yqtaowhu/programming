// Author : yqtao
// Date   : 2016-09-16
// Email  : yqtao@whu.edu.cn

/********************************************************************************** 
* 
* Given a collection of integers that might contain duplicates, S, return all possible subsets.
* 
* Note:
* 
* Elements in a subset must be in non-descending order.
* The solution set must not contain duplicate subsets.
* 
* For example,
* If S = [1,2,2], a solution is:
* 
* [
*   [2],
*   [1],
*   [1,2,2],
*   [2,2],
*   [1,2],
*   []
* ]
* 
*               
**********************************************************************************/
//backtracing
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
	    vector<int>tmp;
	    sort(nums.begin(),nums.end());
	    subsets(nums, tmp, res, 0);
	    return res;
    }
void subsets(vector<int>& nums, vector<int>& tmp, vector<vector<int>>& res, int beg) {
	res.push_back(tmp);
	for (int i = beg; i<nums.size(); i++)
	    if (i == beg || nums[i] != nums[i - 1]){
		    tmp.push_back(nums[i]);
	    	subsets(nums, tmp, res, i + 1);
	    	tmp.pop_back();
	}
}
};
//iterater
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ret(1, vector<int>());
		int size = 0, startIndex = 0;
		for (int i = 0; i<nums.size(); i++) {
			startIndex = (i>= 1 && nums[i] == nums[i - 1]) ? size : 0;
			size = ret.size();
			for (int j = startIndex; j<size; j++) {
				vector<int> tmp = ret[j];
				tmp.push_back(nums[i]);
				ret.push_back(tmp);
			}
		}
		return ret;
	}
};
