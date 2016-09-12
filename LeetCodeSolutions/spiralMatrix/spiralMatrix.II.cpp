// Date   : 2016.09.11
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
* 
* For example,
* Given n = 3,
* 
* You should return the following matrix:
* 
* [
*  [ 1, 2, 3 ],
*  [ 8, 9, 4 ],
*  [ 7, 6, 5 ]
* ]
* 
*               
**********************************************************************************/
class Solution {
public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> res(n,vector<int>(n,1));
            int l=0,t=0,r=n-1,b=n-1,k=1;
            while (l<=r&&t<=r) {
                for (int i=l;i<=r;i++) res[l][i]=k++;
                for (int i=t+1;i<=b;i++) res[i][r]=k++;
                if (t!=b) 
                    for (int i=r-1;i>=l;i--) res[b][i]=k++;
                if (l!=r)
                    for (int i=b-1;i>t;i--) res[i][l]=k++;
                    l++;r--;t++;b--;
            }
            return res;
        }
};
