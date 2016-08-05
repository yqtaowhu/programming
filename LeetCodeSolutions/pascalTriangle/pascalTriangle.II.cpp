// Date   : 2016.08.05
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given an index k, return the kth row of the Pascal's triangle.
* 
* For example, given k = 3,
* Return [1,3,3,1].
* 
* Note:
* Could you optimize your algorithm to use only O(k) extra space?
* 
*               
**********************************************************************************/

#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> v(rowIndex+1, 0);
    v[0]=1;

    for (int i=0; i<rowIndex; i++){
        for(int j=i+1; j>0; j--){
           v[j] += v[j-1];
        } 
    }
    return v;
    
}

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res(rowIndex+1);
        for (int i=0;i<=rowIndex;i++) {
            res[i].resize(i+1);
            res[i][0]=res[i][i]=1;
            for (int j=1;j<i;j++) 
                res[i][j]=res[i-1][j-1]+res[i-1][j];
        }
        return res[rowIndex];
    }
};