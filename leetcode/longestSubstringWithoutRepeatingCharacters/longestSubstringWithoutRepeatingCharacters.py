class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        usedchar = {}
        start = count = 0;
        for i in range(len(s)):
            if s[i] in usedchar and start <= usedchar[s[i]]:
                start = usedchar[s[i]] + 1
            count = max(i-start+1,count)
            usedchar[s[i]] = i
        return count