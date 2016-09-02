// Date   : 2016.09.02
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Write a function to find the longest common prefix string amongst an array of strings.
* 
*               
**********************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
	int n = strs.size();
	string res;
	if (n <= 0) return res;
	for (int i = 1; i <= strs[0].size(); i++) {
		string temp = strs[0].substr(0, i);
		bool match = true;
		for (int j = 1; j<strs.size(); j++) {
			if (i>strs[j].size() || temp != strs[j].substr(0, i)) {
				match = false;
				break;
			}
		}
		if (!match) return res;
		res = temp;
	}
	return res;
}

int main()
{
    const char* s[]={"abab","aba","abc"};
    vector<string> v(s, s+3);
    cout << longestCommonPrefix(v) <<endl;
}
