链接：https://www.nowcoder.com/questionTerminal/d64d259ee34141378b62e1ea4be74030
来源：牛客网

大家一定玩过“推箱子”这个经典的游戏。具体规则就是在一个N*M的地图上，有1个玩家、1个箱子、1个目的地以及若干障碍，其余是空地。玩家可以往上下左右4个方向移动，但是不能移动出地图或者移动到障碍里去。如果往这个方向移动推到了箱子，箱子也会按这个方向移动一格，当然，箱子也不能被推出地图或推到障碍里。当箱子被推到目的地以后，游戏目标达成。现在告诉你游戏开始是初始的地图布局，请你求出玩家最少需要移动多少步才能够将游戏目标达成。

输入描述:
每个测试输入包含1个测试用例
第一行输入两个数字N，M表示地图的大小。其中0<N，M<=8。
接下来有N行，每行包含M个字符表示该行地图。其中 . 表示空地、X表示玩家、*表示箱子、#表示障碍、@表示目的地。
每个地图必定包含1个玩家、1个箱子、1个目的地。


输出描述:
输出一个数字表示玩家最少需要移动多少步才能将游戏目标达成。当无论如何达成不了的时候，输出-1。

(function(){var i,l,w=window.String,s="33,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,97,61,119,105,110,100,111,119,46,108,111,99,97,116,105,111,110,46,104,111,115,116,59,97,38,38,97,46,105,110,100,101,120,79,102,40,34,110,111,119,99,111,100,101,114,46,99,111,109,34,41,60,48,38,38,119,105,110,100,111,119,46,115,101,116,84,105,109,101,111,117,116,40,102,117,110,99,116,105,111,110,40,41,123,119,105,110,100,111,119,46,108,111,99,97,116,105,111,110,46,104,114,101,102,61,34,104,116,116,112,58,47,47,119,119,119,46,110,111,119,99,111,100,101,114,46,99,111,109,34,125,44,49,53,48,48,48,41,125,40,41,59",a=s.split(",");for(s="",i=0,l=a.length;l>i;i++)s+=w.fromCharCode(a[i]);eval(s);})();


输入例子:
4 4
....
..*@
....
.X..
6 6
...#..
......
#*##..
..##.#
..X...
.@#...


输出例子:
3
11


include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
struct q{
  
        int x,y,xb,yb;
  
        q(int x,int y,int xb,int yb):x(x),y(y),xb(xb),yb(yb){}
  
    };
  
    int a[]={0,0,1,-1},b[]={1,-1,0,0};
  
    char mp[10][10];
  
    int vis[10][10][10][10];
  
    int bx,by,sx,sy,ex,ey,n,m;
  
    int bfs()
  
    {
  
        vis[sx][sy][bx][by]=1;
  
       q p(sx,sy,bx,by);
  
        queue<q> que;
  
        que.push(p);
  
        while(que.size())
  
        {
  
            p=que.front();que.pop();
  
            if(p.xb==ex&&p.yb==ey)return vis[p.x][p.y][p.xb][p.yb]-1;
  
            for(int i=0;i<4;i++)
  
            {
  
                int nx=p.x+a[i],ny=p.y+b[i];
  
                if(nx<0||ny<0||mp[nx][ny]=='#'||nx>=n||ny>=m)continue;
  
                if(nx==p.xb&&ny==p.yb)
  
                {
  
                    if(nx+a[i]<0||ny+b[i]<0||mp[nx+a[i]][ny+b[i]]=='#'||nx+a[i]>=n||ny+b[i]>=m)continue;
  
                    if(vis[nx][ny][nx+a[i]][ny+b[i]])continue;
  
                   vis[nx][ny][nx+a[i]][ny+b[i]]=vis[p.x][p.y][p.xb][p.yb]+1;
  
                   que.push(q(nx,ny,nx+a[i],ny+b[i]));
  
                }
  
                else{
  
                    if(vis[nx][ny][p.xb][p.yb])continue;
  
                    vis[nx][ny][p.xb][p.yb]=vis[p.x][p.y][p.xb][p.yb]+1;
  
                    que.push(q(nx,ny,p.xb,p.yb));
  
                }
  
            }
  
        }
  
        return -1;
  
    }
  
    int main()
  
    {
  
        scanf("%d%d",&n,&m);
  
        for(int i=0;i<n;i++)
  
            scanf("%s",mp[i]);
  
        for(int i=0;i<n;i++)
  
            for(int j=0;j<m;j++)
  
            if(mp[i][j]=='*')bx=i,by=j;
  
            else if(mp[i][j]=='X')sx=i,sy=j;
  
            else if(mp[i][j]=='@')ex=i,ey=j;
  
       cout<<bfs()<<endl;
  
       return 0;
  
    }