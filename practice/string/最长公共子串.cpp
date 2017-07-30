//如有相同的输出短串中最先出现的
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string help(string& s,string& p){
    int m=s.size(),n=p.size(),ret=0,index=0;
    if(m>n) return help(p,s);                         //让m为短串的长度，这样能输出短串中最先出现的
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){                            //简单dp
        for(int j=1;j<=n;j++) {
            if(s[i-1]==p[j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;
			    if(ret<dp[i][j]){
                    ret=dp[i][j];
                    index=j;
            	}
            }
            else dp[i][j]=0;
        }
    }
    return p.substr(index-ret,ret);
}
int main(){
	string s,p;
    while(cin>>s>>p){
        cout<<help(s,p)<<endl;
    }
    return 0;
}