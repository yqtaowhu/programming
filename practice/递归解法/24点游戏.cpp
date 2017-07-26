/*******************************************************************
问题描述：给出4个1-10的数字，通过加减乘除，得到数字为24就算胜利
输入：
4个1-10的数字。[数字允许重复，测试用例保证无异常数字]
输出：
true or false
*********************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int ff = 0; int a[4] = { 0 };
void dfs(int idx, int value, int a[]) {
	int i;
	if (value == 24) {
		ff = 1;
		return;
	}
	if (value>24 || idx >= 4)
		return;
	for (i = 0; i<4; ++i) {
		switch (i) {
		case 0:
			dfs(idx + 1, value + a[idx], a);
			break;
		case 1:
			dfs(idx + 1, value - a[idx], a);
			break;
		case 2:
			dfs(idx + 1, value*a[idx], a);
			break;
		case 3:
			dfs(idx + 1, value / a[idx], a);
			break;
		}
		if (ff)
			return;
	}
}
int main() {
	int val = 0;
	while (cin >> a[0] >> a[1] >> a[2] >> a[3]) {
		sort(a, a + 4);
		do {
			dfs(0, val, a);
		} while (next_permutation(a, a + 4));
		ff ? cout << "true" << endl : cout << "false" << endl;
	}
	return 0;
}