#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
using namespace std;
//求DP
vector<int> getLISLength(int num[], int length) {
	vector<int> ivec; //help
	vector<int> dp(length);
	dp[0] = 1;
	ivec.push_back(num[0]);
	for (int i = 1; i < length; ++i) {
		if (ivec.back() < num[i]) {
			ivec.push_back(num[i]);
			dp[i] = dp[i - 1] + 1;
		}
		else {
			int low = 0, high = ivec.size() - 1;
			while (low < high) {
				int mid = (low + high) / 2;
				if (ivec[mid] < num[i])
					low = mid + 1;
				else
					high = mid - 1;
			}
			ivec[low] = num[i];
			dp[i]=low+1;
		}
		
	}
	return dp;
}
int main() {
	int n[] = { 2,1,5,3,6,4,8,9,7 };
	vector<int>dp = getLISLength(n, 9);
	for (auto c : dp)
		cout << c << endl;	
}