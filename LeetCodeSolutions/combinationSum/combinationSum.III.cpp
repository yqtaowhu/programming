// Author : yqtao
// Date   : 2016-09-08
// Email  : yqtao@whu.edu.cn
/********************************************************************************** 
 * 
 * Find all possible combinations of k numbers that add up to a number n, 
 * given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 * Ensure that numbers within the set are sorted in ascending order.
 * 
 *  Example 1:
 * Input:  k = 3,  n = 7
 * Output: 
 * 
 * [[1,2,4]]
 * 
 *  Example 2:
 * Input:  k = 3,  n = 9
 * Output: 
 * 
 * [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
class Solution {
public:
    void combination(int k, int n, vector<int>& v, vector<vector<int>>& ret, int beg){
        if(k == 0 && n == 0){
            ret.push_back(v);
            return;
        }
        for(int i = beg; i < 10 && i <= n; i++){
            v.push_back(i);
            combination(k - 1, n - i, v, ret, i + 1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> v;
        combination(k, n, v, ret, 1);
        return ret;
    }
};
