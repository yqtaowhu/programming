// Author : yqtao
// Date   : 2016-09-13
// Email  : yqtao@whu.edu.cn

/********************************************************************************** 
* 
* Given two binary strings, return their sum (also a binary string).
* 
* For example,
* a = "11"
* b = "1"
* Return "100".
* 
*               
**********************************************************************************/
class Solution {
public:
    string addBinary(string a, string b) {
	int n1 = a.size(), n2 = b.size(), carry = 0, k = 0;
	int i = n1 - 1, j = n2 - 1; string res;
	while (i >= 0 || j >= 0||carry) {
		int x = i >= 0 ? a[i] - '0' : 0;
		int y = j >= 0 ? b[j] - '0' : 0;
		res.insert(res.begin(), (carry + x + y) % 2 + '0');
		carry = (x + y + carry) / 2;
		i--; j--;
	}
	return res;
}
};
