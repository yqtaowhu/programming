// Author : yqtao
// Date   : 2016-11-30
// Email  : yqtao@whu.edu.cn

/************************************************************************************************************
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations 
that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
****************************************************************************************************************/
//solution 1 : recusive,Time limitation
int combination(vector<int>& nums, int target) {
	if (target == 0)
		return 1;
	int res = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (target >= nums[i])
			res += combination(nums, target - nums[i]);
	}
	return res;
}
//solution 2 : DP
int combination(vector<int>& nums, int target) {
	vector<int>comb(target + 1, 0);
	comb[0] = 1;
	for (int i = 1; i < comb.size(); i++) {
		for (int j = 0; j < nums.size(); j++) {
			if (i - nums[j] >= 0)
				comb[i] += comb[i - nums[j]];
		}
	}
	return comb[target];
}