/************************************************************************************
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。
 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
 ****************************************************************************************/
 //bfs的套路，队列，vis数组
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


/*****************************************************************
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如[a b c e s f c s a d e e]是3*4矩阵
，其包含字符串"bcced"的路径，但是矩阵中不包含“abcb”路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*******************************************************************/
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str) {
        vector<bool>visit(strlen(matrix),false);
    	for (int i=0;i<rows;i++) {
            for (int j=0;j<cols;j++) {
				int len=strlen(str);
                if (check(matrix,i,rows,j,cols,0,visit,str)) 
                    return true;
            }
        }
        return false;
    }
    bool check(char* matrix,int i,int rows,int j,int cols,int k,vector<bool>& visit,char* str) {
        int index=i*cols+j;
        if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || visit[index] ==true)
            return false;
        if (k==strlen(str)-1) return true;
        visit[index]=true;
        if (check(matrix, i-1,rows,j,cols, k + 1, visit,str)
                || check(matrix, i,rows,j-1,cols, k + 1, visit,str)
                || check(matrix, i,rows,j+1,cols, k + 1, visit,str)
                || check(matrix, i+1,rows,j,cols, k + 1, visit,str)) 
            return true;
        visit[index] = 0;  //回溯
        return false;
    }
};