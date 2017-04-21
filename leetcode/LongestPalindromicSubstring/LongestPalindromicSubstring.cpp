// Date   : 2016.08.09
// Author : yqtao
// https://github.com/yqtaowhu
/********************************************************************************** 
* 
* Given a string S, find the longest palindromic substring in S. 
* You may assume that the maximum length of S is 1000, 
* and there exists one unique longest palindromic substring.
*               
**********************************************************************************/
// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
 
  ret += "#$";
  return ret;
}
 
string longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)
    
    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
    
    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;
 
    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }
 
  // Find the maximum element in P.
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
  delete[] P;
  
  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}
//another way ,it may slower than above,but it can easy to understand
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
//测试
int main()
{
    string s = "abadcacd";
    string result = longestPalindrome(s);
    cout << result << endl;
}