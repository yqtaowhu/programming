//https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8?tpId=13&tqId=11219&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    
    int movingCount(int threshold, int rows, int cols) {
		if (threshold<0) return 0;
        if (threshold==0) return 1;
        vector<vector<int>> vis(rows,vector<int>(cols,0));
       	int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>>que;
        que.push({0,0});
        int sum = 1;
        vis[0][0]=1;
        while(!que.empty()) {
            for (int k=0;k<4;k++) {
                int tx = que.front().first + dir[k][0];
                int ty = que.front().second + dir[k][1];
                if (tx<0||tx>=rows||ty<0||ty>=cols||vis[tx][ty]==1)
            		continue;
                if (getsum(tx)+getsum(ty)<=threshold) {
                    sum++;
                    que.push({tx,ty});
                    vis[tx][ty]=1;
                }
            }
            que.pop();
        }
        return sum;
    }
    int getsum(int x) {
        int ret = 0;
        while(x) {
			ret += x%10;
            x/=10;
        }
        return ret;
    } 
};
