// Date   : 2016.08.05
// Author : yqtao
// https://github.com/yqtaowhu
/***************************************************************************
Implement strStr().
Returns the index of the first occurrence of needle in haystack,
or -1 if needle is not part of haystack.
*****************************************************************************/
//simple way ,O(N^2)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1=haystack.size(),n2=needle.size();
        if(n2==0) return 0;
        if (n1<n2) return -1;
        int i=0,j=0;
        for (i=0;i<=n1-n2;i++) {
            for (j=0;j<n2;j++) {
                if (needle[j]!=haystack[i+j]) 
                    break;
            }
            if (j==n2) return i;
        }
        return -1;
    }
};
//kmp algorithm
class Solution {
public:
    int strStr(string haystack, string needle) {
	    int m = haystack.size(), n = needle.size();
	    if (n == 0) return 0;
	    if (m<n) return -1;
	    vector<int> next = getNext(needle);
	    int i = 0, j = 0;
	    while (i<m&&j<n) {
		    if (j == -1 || haystack[i] == needle[j]) {
			    i++; j++;
		    }
		    else  j = next[j];
	    }
	    return j == n ? i - j : -1;
    }
    vector<int> getNext(string &haystack) {
        vector<int>next(haystack.size(),-1);
        int k=-1,j=0;
        while (j<haystack.size()-1) {
            if (k==-1||haystack[j]==haystack[k]) {
                ++k;++j;
                if (haystack[j]!=haystack[k])
                    next[j]=k;
                else 
                    next[j]=next[k];
            }
            else k=next[k];
        }
        return next;
    }
};