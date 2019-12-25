/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size(), cols = image[0].size();
        queue<pair<int,int> > que;
        vector<vector<int> > vis(rows, vector<int>(cols,0));
        que.push({sr,sc});
        int next[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
        int oldColor = image[sr][sc];
        vis[sr][sc] = 1;
        while(!que.empty()) {
            int x = que.front().first, y = que.front().second;
            //cout << x << " " << y << endl; 
            image[x][y] = newColor;
            que.pop();
            for(int i=0; i < 4; i++) {
                int tx = x + next[i][0];
                int ty = y + next[i][1];
                if(tx>=0 && tx<rows && ty>=0 && ty<cols && vis[tx][ty] == 0 && image[tx][ty] == oldColor) {
                    que.push({tx,ty});
                    vis[x][y] = 1;
                }
            }
        }
        return image;
    }
};
// @lc code=end

