/**************************************************************************************************
链接：https://www.nowcoder.com/questionTerminal/28c1dc06bc9b4afd957b01acdf046e69
来源：牛客网
给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
 输出需要删除的字符个数。
输入描述:
输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
 
输出描述:

对于每组数据，输出一个整数，代表最少需要删除的字符个数。

输入例子:
abcda
google


输出例子:
2
2
*************************************************************************************************/
//链接：https://www.nowcoder.com/questionTerminal/28c1dc06bc9b4afd957b01acdf046e69
来源：牛客网
/*
提到回文串，自然要利用回文串的特点，想到将源字符串逆转后，“回文串”（不一定连续）
相当于顺序没变 求原字符串和其反串的最大公共子序列（不是子串，因为可以不连续）的长度（使用动态规划很容易求得），
然后用原字符串的长度减去这个最大公共子序列的长度就得到了最小编辑长度
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int help(string p, string s) {
	int len = p.size();
	vector<vector<int>>dp(len + 1, vector<int>(len + 1, 0));
	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= len; j++) {
			if (p[i-1] == s[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[len][len];
}
int main() {
	string s;
	while (cin >> s) {
		string p = s;
		reverse(p.begin(), p.end());
		int size=help(p,s);  //求最长公共子序列
		cout << p.size() - size << endl;
	}
}