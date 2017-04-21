// Date   : 2016.08.10
// Author : yqtao
// https://github.com/yqtaowhu
/********************************************************************************** 
 * 
 * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 * 
 * Try to solve it in linear time/space.
 * 
 * Return 0 if the array contains less than 2 elements.
 * 
 * You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 * 
 * Credits:Special thanks to @porker2008 for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
using namespace std;
int maximumGap(vector<int>& nums) {
	int n = nums.size();
	if (n < 2) return 0;
	auto lh= minmax_element(nums.begin(), nums.end());
	int min_value = *lh.first, max_value = *lh.second;
	if (min_value == max_value) return 0;
	vector<bool> flag(n + 1, false); //表示桶是否为空
	vector<int> bucketMin(n+1,0);
	vector<int> bucketMax(n+1,0);
	for (int i = 0; i< n; i++) {    //分配桶号，和桶的最大最小值
		int bid = static_cast<int>((nums[i] - min_value) / (max_value - min_value + 0.0)*n);  //获得桶号
		bucketMin[bid] = flag[bid] ? min(bucketMin[bid], nums[i]) : nums[i];
		bucketMax[bid] = flag[bid] ? max(bucketMax[bid], nums[i]) : nums[i];
		flag[bid] = true;
	}
	int max_result = bucketMax[0], result = 0;
	for (int i = 1; i < n + 1; i++) {
		if (flag[i]) {
			result = max(bucketMin[i] - max_result, result);
			max_result = bucketMax[i];  //每次更新桶值
		}
	}
	return result;
}
int main() {
	vector<int> v = { 601408776,63967816,431363697,242509930,15970592,60284088,228037800,147629558};
	cout << maximumGap(v) << endl;	
}
