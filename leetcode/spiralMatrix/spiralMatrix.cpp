// Author : yqtao
// Date   : 2016-09-10
// Email  : yqtao@whu.edu.cn

/********************************************************************************** 
* 
* Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
* 
* For example,
* Given the following matrix:
* 
* [
*  [ 1, 2, 3 ],
*  [ 4, 5, 6 ],
*  [ 7, 8, 9 ]
* ]
* 
* You should return [1,2,3,6,9,8,7,4,5].
* 
*               
**********************************************************************************/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int row=matrix.size(),col=matrix[0].size();
        int left=0,top=0,bottom=row-1,right=col-1;
        while (left<=right&&top<=bottom) {
            for (int i=left;i<=right;i++) res.push_back(matrix[left][i]);
            for (int i=top+1;i<=bottom;i++) res.push_back(matrix[i][right]);
            if (top!=bottom)
                for (int i=right-1;i>=left;i--) res.push_back(matrix[bottom][i]);
            if (left!=right)
                for (int i=bottom-1;i>top;i--) res.push_back(matrix[i][left]);
            left++;right--;top++;bottom--;
        }
        return res;
    }
};
