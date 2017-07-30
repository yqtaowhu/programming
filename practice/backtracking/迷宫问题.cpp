定义一个二维数组N*M（其中2<=N<=10;2<=M<=10），如5 × 5数组下所示： 

int maze[5][5] = {

        0, 1, 0, 0, 0,

        0, 1, 0, 1, 0,

        0, 0, 0, 0, 0,

        0, 1, 1, 1, 0,

        0, 0, 0, 1, 0,

};

它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。入口点为[0,0],既第一空格是可以走的路。
Input
一个N × M的二维数组，表示一个迷宫。数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。

#include<iostream>
#include<vector>
using namespace std;
//dfs+backtracing
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<pair<int,int>> res;
void dfs(int x, int y, vector<vector<int>>&map, vector<pair<int, int>>& path) {
	int row = map.size()-1, col = map[0].size()-1;
	map[x][y] = -1; //做标记,表示已经访问了
	path.push_back({ x,y });
	//4个方向遍历,dfs
	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (tx<1 || tx>row || ty<1 || ty>col) continue;
		//满足条件
		if (tx == row&&ty == col) {
			if (res.size()<path.size())
				res = path;
			return;
		}
		if (map[tx][ty] == 0)
			dfs(tx, ty, map, path);
	}
	path.pop_back();
}
int main() {
	int m, n;
	while (cin >> m >> n) {
		vector<vector<int>> map(m + 1, vector<int>(n + 1, 1));
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++)
				cin >> map[i][j];
		}
		vector<pair<int,int>>path;
		dfs(1,1,map, path);
		for (auto i : res)
			cout << "(" << i.first - 1 << "," << i.second - 1 << ")" << endl;
		cout << "(" << m - 1 << "," << n - 1 << ")"<<endl ;
        res.clear();
	}
}