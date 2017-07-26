
有一些零钱，最少多少加起来等于一个数！
1,2,5=》11  5  5 1=》3

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
	int Max = amount + 1;
	vector<int>dp(amount + 1, Max);
	dp[0] = 0;
	//i为要组成的数
	for (int i = 1; i <= amount; i++) {
		for (int j = 0; j<coins.size(); j++) {
			//硬币小于i才进行下一步
			if (coins[j] <= i) {
				//i-coins[j]即剩余的钱数的最优的组成个数,再加1
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				cout << dp[i] << endl;
			}
		}
	}
	return dp[amount] == Max ? -1 : dp[amount];
}
int main(){
	vector<int> v = { 1,2,5 };
	cout << coinChange(v, 11) << endl;
	return 0;
}