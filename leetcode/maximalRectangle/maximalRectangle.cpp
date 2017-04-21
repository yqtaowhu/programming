// Date   : 2016.09.16
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle 
* containing all ones and return its area.
*               
**********************************************************************************/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
    if (height.size()<=0) return 0;
    height.push_back(0);
    vector<int> stack;
    int maxArea=0;
    for(int i=0; i<height.size(); ){
        if (stack.size()==0 || height[i] >= height[ stack.back() ] ){
            stack.push_back(i);
            i++;
        }else{
            int topIdx = stack.back();
            stack.pop_back();
            int area = height[topIdx] * ( stack.size()==0 ? i  : i - stack.back() - 1 );
            if (area > maxArea) maxArea = area;
        }
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char> > &matrix) {

    if (matrix.size()<=0 || matrix[0].size()<=0) return 0;
    int row = matrix.size();
    int col = matrix[0].size();
    vector< vector<int> > heights(row, vector<int>(col));

    int maxArea = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++) {
            if (matrix[i][j]=='1'){
                heights[i][j] = (i==0 ? 1 : heights[i-1][j] + 1);
            }
        }
        int area = largestRectangleArea(heights[i]);
        if (area > maxArea) maxArea = area;
    }
    return maxArea;
}
};



