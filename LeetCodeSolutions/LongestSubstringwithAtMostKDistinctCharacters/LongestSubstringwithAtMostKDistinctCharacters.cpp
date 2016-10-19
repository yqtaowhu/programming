// Date   : 2016.10.19
// Author : yqtao
// https://github.com/yqtaowhu
/**********************************************************************************************************
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
**********************************************************************************************************/
#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int lengthOfLongestSubstringKDistinct(string s, int k) {
	int beg = 0, end = 0, count = 0, counter = 0;
	map<char, int> m;
	while (end < s.size()) {
		if (m[s[end++]]++ == 0) counter++;
		while (counter > k) 
			if (m[s[beg++]]--==1) counter--;
		count = max(count, end - beg);
	}
	return count;
}
int main() {
	cout << lengthOfLongestSubstringKDistinct("eceba",3) << endl;
	cout << lengthOfLongestSubstringKDistinct("ecebabcsddada",3) << endl;
	cout << lengthOfLongestSubstringKDistinct("ecebabcsddada", 1) << endl;
	cout << lengthOfLongestSubstringKDistinct("ecebabbasddada", 4) << endl;
}