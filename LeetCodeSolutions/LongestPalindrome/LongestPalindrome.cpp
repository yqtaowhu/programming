// Date   : 2016.10.09
// Author : yqtao
// https://github.com/yqtaowhu
/*********************************************************************************************
Longest Palindrome
Given a string which consists of lowercase or uppercase letters, 
find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.
Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*************************************************************************************************/
//my way , is esay to understand
class Solution {
public:
    int longestPalindrome(string s) {
        int even=0,odd=0;
        if (s.empty()) return 0;
        map<char,int> m;
        for (int i=0;i<s.size();i++) 
            m[s[i]]++;
        bool isOdd=false;
        for (int i=0;i<s.size();i++) {
            if (m[s[i]]%2==0) {
                even+=m[s[i]];
                m[s[i]]=0;
            }
            else {
                isOdd=true;
                odd+=m[s[i]]-1;
                m[s[i]]=0;
            }
        }
        return isOdd ? odd+even+1 : even;
    }
};
//others way ,very clever
class Solution {
public:
     int longestPalindrome(string s) {
        if (s.size() <= 1) return s.size();
        int count = 0, list[256] = { 0 };
        for (auto c : s) list[c]++;
        for (auto n : list) count += (n % 2)? n - 1 : n;
        return (count < s.size()) ? count + 1 : count;
    }
};