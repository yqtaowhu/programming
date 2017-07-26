//´óÊýÏà¼Ó.
string bigAdd(string a, string b) {
	int m = a.size(), n = b.size();
	if (m<n) return bigAdd(b, a);
	string sum(m+1,'0');
	int i = m - 1, j = n - 1, k = m;
	int carry = 0;
	while (i >= 0 && j >= 0) {
		int tmp = carry + (a[i--] - '0') + (b[j--] - '0');
		sum[k--] = tmp % 10 + '0';
		carry = tmp / 10;
	}
	while (i >= 0) {
		int tmp = carry + (a[i--] - '0');
		sum[k--] = tmp % 10 + '0';
		carry = tmp / 10;
	}
	if (carry) sum[0] = '1';
	size_t startpos = sum.find_first_not_of("0");
	if (string::npos != startpos)
		return sum.substr(startpos);
	return "0";
}

//´óÊýÏà³Ë
class Solution {
public:
    string multiply(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');
    
    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }
    
    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
}
};
