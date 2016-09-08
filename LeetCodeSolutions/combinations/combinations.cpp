// Author : yqtao
// Date   : 2016-09-08
// Email  : yqtao@whu.edu.cn
/********************************************************************************** 
* 
* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
* 
* For example,
* If n = 4 and k = 2, a solution is:
* 
* [
*   [2,4],
*   [3,4],
*   [2,3],
*   [1,2],
*   [1,3],
*   [1,4],
* ]
* 
*               
**********************************************************************************/
//backtracing solution
class Solution {
public:
    void combination(int n,int k,int beg,vector<int>& v,vector<vector<int>>& res) {
        if (k==0) {
            res.push_back(v);
            return; 
        }
        for (int i=beg;i<=n&&k>0;i++) {
            v.push_back(i);
            combination(n,k-1,i+1,v,res);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>v;
        combination(n,k,1,v,res);
        return res;
    }
};
