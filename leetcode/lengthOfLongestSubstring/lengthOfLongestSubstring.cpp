// Author : yqtao
// Date   : 2016-7-3
// Email  : yqtao@whu.edu.cn
/******************************************************************************************************************
*Given a string, find the length of the longest substring without repeating characters.
*Examples:
*
*Given "abcabcbb", the answer is "abc", which the length is 3.
*Given "bbbbb", the answer is "b", with the length of 1.
*
*Given "pwwkew", the answer is "wke", with the length of 3. 
*Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*******************************************************************************************************************/
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
/*
* Idea:
*
* Using a map store each char's index.
*
* So, we can be easy to know the when duplication and the previous duplicated char's index.
*
* Then we can take out the previous duplicated char, and keep tracking the maxiumn length.
*
*/
int lengthOfLongestSubstring(string s) 
{
	map<char, int> m;   
	int maxLen = 0;
	int lastRepeatPos = -1;   //last repeatpos ,so i- lastrepeatpos is the length;
	for (int i = 0; i<s.size(); i++) {
		if (m.find(s[i]) != m.end() && lastRepeatPos < m[s[i]]) {
			lastRepeatPos = m[s[i]];
		}
		if (i - lastRepeatPos > maxLen) {
			maxLen = i - lastRepeatPos;
		}
		m[s[i]] = i;
	}
	return maxLen;
}

//without using map,but,the idea is the same with map
int lengthOfLongestSubstring1(string s) {
	vector<int> dict(256, -1);
	int maxLen = 0, lastRepeatPos = -1;
	for (int i = 0; i != s.length(); i++) {
		if (dict[s[i]]!=-1&&dict[s[i]] > lastRepeatPos)
			lastRepeatPos = dict[s[i]];
		dict[s[i]] = i;
		if (i - lastRepeatPos > maxLen) {
			maxLen = i - lastRepeatPos;
		}
	}
	return maxLen;
}
int main()
{
	string s = "dvdf";
	//cout << lengthOfLongestSubstring(s) << endl;
	cout << lengthOfLongestSubstring1(s) << endl;
}