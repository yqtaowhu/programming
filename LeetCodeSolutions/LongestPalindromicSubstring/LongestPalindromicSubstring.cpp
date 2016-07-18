//Author: yqtao
//Email : yqtao@whu.edu.cn
//Date  :2016.7.4
/************************************************************************
*Given a string S, find the longest palindromic substring in S.
*You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*
*S="abadcacd"   ,return "dcacd"
**********************************************************************************/
/*    idea:
**    using j is the starting point of each palindromic string, k is the end point.
**    each iteration we use i as the "mid" of the palindromic string
**************************************************************************************/
#include<iostream>
#include <algorithm>
#include <string>
using namespace std;
string longestPalindrome(string s) {
	if (s.empty()) return "";
	if (s.size() == 1) return s;
	int min_start = 0, max_len = 1;      //
	for (int i = 0; i < s.size();) {
		if (s.size() - i <= max_len / 2) break;
		int j = i, k = i;       //j is a pre pointer,k is next pointer
		while (k < s.size() - 1 && s[k + 1] == s[k])
			++k; // Skip duplicate characters.
		i = k + 1;
		while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1])
		{
			++k;
			--j;
		} // Expand.
		int new_len = k - j + 1;
		if (new_len > max_len)
		{
			min_start = j;
			max_len = new_len;
		}
	}
	return s.substr(min_start, max_len);
}
//≤‚ ‘
int main()
{
	string s = "abadcacd";
	string result = longestPalindrome(s);
	cout << result << endl;
}
