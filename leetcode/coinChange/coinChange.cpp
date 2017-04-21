// Date   : 2016.08.15
// Author : yqtao
// https://github.com/yqtaowhu

/*************************************************************************************** 
 *
 * You are given coins of different denominations and a total amount of money amount. 
 * Write a function to compute the fewest number of coins that you need to make up that
 * amount. If that amount of money cannot be made up by any combination of the coins,
 * return -1.
 * 
 * Example 1:
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 * 
 * Example 2:
 * coins = [2], amount = 3
 * return -1.
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test 
 * cases.
 * 
 ***************************************************************************************/
//DP implmentation
//dp[i]=min(dp[i],dp[i-coins[j]]+1);
//where i is the sum we collect is min coins ,for example 
//i=6,we should using 5,1coins it 2 coins;
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
	const int MAX = amount + 1;
	vector<int> dp(amount + 1, MAX);
	dp[0] = 0;

	for (int i = 1; i <= amount; i++) {
		for (int j = 0; j<coins.size(); j++) {
			if (i >= coins[j]) {
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}

	return dp[amount] == MAX ? -1 : dp[amount];
}
int main()
{
	vector<int>v = { 2,1,5 };
	cout << coinChange(v, 11) << endl;
}
