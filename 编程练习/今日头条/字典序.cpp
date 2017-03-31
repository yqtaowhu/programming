#include<iostream>  
#include<vector>  
#include<algorithm>  
using namespace std;
typedef long long ll;
vector<int> vec;
ll cal(int p, bool flag){
	ll ans = 0, t = 1;
	for (int i = p; i < (int)vec.size() - 1; i++) {
		ans += t;
		t *= 10;
	}
	if (!flag) {
		ans += t;
	}
	else {
		ll z = 0;
		for (int i = p + 1; i < (int)vec.size(); i++) {
			z = z * 10 + vec[i];
		}
		z++;
		ans += z;
	}
	return ans;
}
ll solve(ll n, ll m){
	ll t = n;
	while (t) {
		vec.push_back(t % 10);
		t /= 10;
	}
	reverse(vec.begin(), vec.end());
	ll ans = 0;
	bool flag = true;
	for (int i = 0; m > 0; i++) {
		for (int j = (i == 0 ? 1 : 0); j <= 9; j++) {
			ll sum;
			if (flag) {
				if (j < vec[i]) {
					sum = cal(i, 0);
				}
				else if (j == vec[i]) {
					sum = cal(i, 1);
				}
				else {
					sum = cal(i + 1, 0);
				}
			}
			else {
				sum = cal(i, 0);
			}
			if (m <= sum) {
				if (flag) {
					if (j < vec[i]) {
						flag = 0;
					}
					else if (j == vec[i]) {
					}
					else {
						flag = 0, i++;
					}
				}
				ans = ans * 10 + j;
				m--;
				break;
			}
			else {
				m -= sum;
			}
		}
	}
	return ans;
}

int main(int argc, const char *argv[]){
	ll n, m;
	cin >> n >> m;
	cout << solve(n, m) << endl;
	return 0;
}