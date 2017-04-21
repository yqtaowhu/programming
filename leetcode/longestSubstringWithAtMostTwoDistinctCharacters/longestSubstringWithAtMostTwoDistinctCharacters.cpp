// Date   : 2016.10.19
// Author : yqtao
// https://github.com/yqtaowhu

/**********************************************************************************************************
 * Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
 * 
 * For example, Given s = “eceba”,
 * 
 * T is "ece" which its length is 3.
 ***********************************************************************************************/
#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int lengthOfLongestSubstringTwoDistinct(string s) {
	int beg = 0, end = 0, count = 0, counter = 0;
	map<char, int> m;
	while (end < s.size()) {
		if (m[s[end++]]++ == 0) counter++;
		while (counter > 2) 
			if (m[s[beg++]]--== 1) counter--;
		count = max(count, end - beg);
	}
	return count;
}
int main() {
	cout << lengthOfLongestSubstringTwoDistinct("eceba") << endl;
	cout << lengthOfLongestSubstringTwoDistinct("ecebabcsddada") << endl;
}
