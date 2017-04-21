//Author	: yqtao
//date		: 2016.10.22
//Email		: yqtao@whu.edu.cn
 /*********************************************************************************************************
 Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

Note:
Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.

Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.
************************************************************************************************/
 class Solution {
 public:
 int trapRainWater(vector<vector<int>>& h) {
     int n = h.size();
     if(n == 0) return 0;
     int m = h[0].size();
     vector<vector<bool> > vis(n, vector<bool>(m, 0));
     priority_queue<pair<int, pair<int, int> > > q;
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
             if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                 vis[i][j] = 1;
                 q.push({-h[i][j], {i, j}});
             }
         }
     }
     int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }; 
     long long res = 0;
     while(!q.empty()) {
             int u = -q.top().first;
         int ux = q.top().second.first;
         int uy = q.top().second.second;
         q.pop();
         for (int i = 0; i < 4; i++) {
             int x = ux + next[i][0];
             int y = uy + next[i][1];
             if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y])
                 continue;
             if(h[x][y] < u) {
                 res += u - h[x][y];
                 h[x][y] = u;
             }
             vis[x][y] = 1;
             q.push({-h[x][y],{x, y} });
         }
     }
     return res;
 }
 };