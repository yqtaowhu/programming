//将十进制转换成n进制
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int m, n;
	while (cin >> m >> n) {
		string ret;
		bool flag = false;
		if (m <= 0) flag = true;
	    m = abs(m);
		while (m) {
			int tmp = m%n;
			if (tmp >= 10) {
				tmp += 55;
				char tmp1 = char(tmp);
				ret += tmp1;
			}
			else 
				ret += tmp+'0';
			m /= n;
		}
		if (flag) ret += '-';
		reverse(ret.begin(), ret.end());
		cout << ret << endl;
	}
}