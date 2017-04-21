// Date   : 2016.08.05
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given numRows, generate the first numRows of Pascal's triangle.
* 
* For example, given numRows = 5,
* Return
* 
* [
*      [1],
*     [1,1],
*    [1,2,1],
*   [1,3,3,1],
*  [1,4,6,4,1]
* ]
* 
*               
**********************************************************************************/
//very beautiful solution .using resize control the size .
class Solution {
public:
   vector<vector<int> > generate(int numRows) {
        vector<vector<int>> r(numRows);
        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        return r;
    }
};