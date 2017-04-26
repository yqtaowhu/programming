#include<iostream>
#include<vector>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
	vector<int> v;
	for (int i = 0; i<nums.size(); i++) {
		if (v.size() == 0 || v.back()<nums[i])
			v.push_back(nums[i]);
		else {
			int low = 0, high = v.size() - 1;
			while (low <= high) {
				int mid = low + (high - low) / 2;
				if (v[mid]<nums[i]) low = mid + 1;
				else  high = mid - 1;
			}
			v[low] = nums[i];
		}
	}
	return v.size();
}
int main() {
	int num, i;
	vector<int>res;
	while (cin >> num) {
		while (num--) {
			cin >> i;
			res.push_back(i);
		}
		cout << lengthOfLIS(res) << endl;
		res.clear();
	}
}
