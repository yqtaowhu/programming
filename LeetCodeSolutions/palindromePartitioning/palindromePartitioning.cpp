// Date   : 2016.09.25
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a string s, partition s such that every substring of the partition is a palindrome.
* 
* Return all possible palindrome partitioning of s.
* 
* For example, given s = "aab",
* 
* Return
* 
*   [
*     ["aa","b"],
*     ["a","a","b"]
*   ]
* 
*               
**********************************************************************************/
//DFS
class Solution {
public:
    vector< vector<string> > partition(string s) {
        vector< vector<string> > result;
        vector<string> output;
        partitionHelper(s, 0,  output, result);
        return result;
}
   void partitionHelper(string &s, int start, vector<string> &output, vector< vector<string> > &result) {
        if (start == s.size()) {
            result.push_back(output);
            return;
        }
        for(int i=start; i<s.size(); i++) {
            if ( isPalindrome(s, start, i) == true ) {
                output.push_back(s.substr(start, i-start+1) );
                partitionHelper(s, i+1, output, result);
                output.pop_back();          //为了装入更长的回文串
            }
        }
    }
    bool isPalindrome(string &s, int start, int end)  {  
    while(start < end) {  
        if(s[start] != s[end]) { 
            return false;  
        }
        start++; end--;  
    }  
    return true;  
} 
};
