// Date   : 2016.08.31
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* The set [1,2,3,…,n] contains a total of n! unique permutations.
* 
* By listing and labeling all of the permutations in order,
* We get the following sequence (ie, for n = 3):
* 
* "123"
* "132"
* "213"
* "231"
* "312"
* "321"
* 
* Given n and k, return the kth permutation sequence.
* 
* Note: Given n will be between 1 and 9 inclusive.
*               
**********************************************************************************/
//
class Solution {
public:
   string getPermutation(int n, int k) {
    int i,j,f=1;
    // left part of s is partially formed permutation, right part is the leftover chars.
    string s(n,'0');
    for(i=1;i<=n;i++){
        f*=i;
        s[i-1]+=i; // make s become 1234...n
    }
    for(i=0,k--;i<n;i++){
        f/=n-i;
        j=i+k/f; // calculate index of char to put at s[i]
        char c=s[j];
        // remove c by shifting to cover up (adjust the right part).
        for(;j>i;j--)
            s[j]=s[j-1];
        k%=f;
        s[i]=c;
    }
    return s;
}
};
//
class Solution {
public:
     string getPermutation(int n, int k) {
        // initialize a dictionary that stores 1, 2, ..., n. This string will store the permutation.
        string dict(n, 0);
        iota(dict.begin(), dict.end(), '1');
        
        // build up a look-up table, which stores (n-1)!, (n-2)!, ..., 1!, 0!
        vector<int> fract(n, 1);
        for (int idx = n - 3; idx >= 0; --idx) {
            fract[idx] = fract[idx + 1] * (n - 1 - idx);
        }
        
        // let k be zero base
        --k;
        
        // the main part.
        string ret(n, 0);
        for (int idx = 0; idx < n; ++idx) {
            int select = k / fract[idx];
            k %= fract[idx];
            ret[idx] = dict[select];
            dict.erase(next(dict.begin(), select)); // note that it is an O(n) operation
        }
        return ret;
    }
};

