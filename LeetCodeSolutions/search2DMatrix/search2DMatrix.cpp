// Date   : 2016.09.15
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Write an efficient algorithm that searches for a value in an m x n matrix. 
* This matrix has the following properties:
* 
* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.
* 
* For example,
* 
* Consider the following matrix:
* 
* [
*   [1,   3,  5,  7],
*   [10, 11, 16, 20],
*   [23, 30, 34, 50]
* ]
* 
* Given target = 3, return true.
*               
**********************************************************************************/
//binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size(),cols=matrix[0].size();
        if (rows==0||cols==0) return false;
        int num=rows*cols;int i=0,j=num-1;
        while (i<=j) {
            int mid=(i+j)>>1;
            int row=mid/cols,col=mid%cols;
            if (matrix[row][col]==target) return true;
            else if (matrix[row][col]<target) i=mid+1;
            else j=mid-1;
        }
        return false;
    }
};
