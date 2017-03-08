//题目链接：https://www.nowcoder.com/question/next?pid=4236887&qid=78086&tid=6964684
/******************************************************************************************************************
如果一个数字能表示为p^q(^表示幂运算)且p为一个素数,q为大于1的正整数就称这个数叫做超级素数幂。现在给出一个正整数n,
如果n是一个超级素数幂需要找出对应的p,q。 
输入描述:
输入一个正整数n(2 ≤ n ≤ 10^18)
输出描述:
如果n是一个超级素数幂则输出p,q,以空格分隔,行末无空格。
如果n不是超级素数幂，则输出No

输入例子:
27

输出例子:
3 3
*******************************************************************************************************************/
#include <iostream>
#include <math.h>
using namespace std;
long long n;
//快速幂
long long calc(long long base, int exp) {
	long long ret = 1;
	while (exp) {
		if (exp & 1)
			ret *= base;
		exp = exp >> 1;
		base *= base;
	}
	return ret;
}
//判断素数
bool check(long long n) {
	long long temp = sqrt(n);
	for (long long i = 2; i <= temp; i++) {
		if (n%i == 0) return false;
	}
	return true;
}
int main() {
	cin >> n;
	int flag = 1;
	//暴力枚举q的值
	for (int i = 2; ; i++) {
		double temp = pow(n, 1.0 / i);
		if (temp < 2.0) break;
		if (calc((long long)temp, i) == n&&check((long long)temp)) {
			flag = 0;
			cout << (long long)temp << " " << i << endl;
		}
	}
	if (flag)
		cout << "No" << endl;
}