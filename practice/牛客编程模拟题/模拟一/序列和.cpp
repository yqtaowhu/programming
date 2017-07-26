/************************************************************************************
给出一个正整数N和长度L，找出一段长度大于等于L的连续非负整数，他们的和恰好为N。
答案可能有多个，我我们需要找出长度最小的那个。
例如 N = 18 L = 2：
5 + 6 + 7 = 18 
3 + 4 + 5 + 6 = 18
都是满足要求的，但是我们输出更短的 5 6 7

输入描述:
输入数据包括一行：
两个正整数N(1 ≤ N ≤ 1000000000),L(2 ≤ L ≤ 100)

输出描述:
从小到大输出这段连续非负整数，以空格分隔，行末无空格。如果没有这样的序列或者找出的序列长度大于100，则输出No
输入例子:
18 2
输出例子:
5 6 7
********************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
vector <int> sequence(int S, int L0) {
	vector<int> R;
	for (int L = L0; L <= 100; L++) {
		//即长度为L的最小和要小于S才行，其次(S-min_sum)%l==0这样才能让每一个小数加入一个相同的值即可
		if (S - L * (L - 1) / 2 >= 0 && (S - L * (L - 1) / 2) % L == 0) {
			int A = (S - L * (L - 1) / 2) / L;
			for (int i = 0; i < L; i++) R.push_back(A + i);
			return R;
		}
	}
	return R;
}
int main() {
	int S, L;
	cin >> S >> L;
	vector<int> ans;
	ans = sequence(S, L);
	if (ans.size() == 0) cout << "No" << endl;
	else {
		for (int i = 0; i < ans.size()-1; i++) {
                cout<<ans[i]<<" ";         
		}
		//要求行末无空格
        cout<<ans[ans.size()-1];
	}
	return 0;
}