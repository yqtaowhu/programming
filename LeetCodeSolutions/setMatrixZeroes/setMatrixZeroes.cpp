// Date   : 2016.09.15
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
* 
* click to show follow up.
* 
* Follow up:
* 
* Did you use extra space?
* A straight forward solution using O(mn) space is probably a bad idea.
* A simple improvement uses O(m + n) space, but still not the best solution.
* Could you devise a constant space solution?
* 
*               
**********************************************************************************/
//very esay way,just remember the 0 position
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int>zero;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++)
              if(matrix[i][j]==0) {
                  zero.push_back(i);
                  zero.push_back(j);
              }
        }
        for (int i=0;i<zero.size();i+=2) {
            int row=zero[i];
            int col=zero[i+1];
            for (int j=0;j<n;j++) matrix[row][j]=0;
            for (int j=0;j<m;j++) matrix[j][col]=0;
        }
    }
};
//another way O(1) SPACE
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
}
};