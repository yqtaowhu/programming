/***************************************************************************************
牛牛的好朋友羊羊在纸上写了n+1个整数，羊羊接着抹除掉了一个整数，给牛牛猜他抹除掉的数字是什么。
牛牛知道羊羊写的整数神排序之后是一串连续的正整数，牛牛现在要猜出所有可能是抹除掉的整数。例如：
10 7 12 8 11 那么抹除掉的整数只可能是9
5 6 7 8 那么抹除掉的整数可能是4也可能是9

输入描述:
输入包括2行：

第一行为整数n(1 <= n <= 50)，即抹除一个数之后剩下的数字个数

第二行为n个整数num[i] (1 <= num[i] <= 1000000000)


输出描述:
在一行中输出所有可能是抹除掉的数,从小到大输出,用空格分割,行末无空格。如果没有可能的数，则输出mistake

输入例子:
2
3 6

输出例子:
mistake
************************************************************************************/
//要注意的一点是不能输出0啊！！！！！！！！！！！！！！！！！！！！！！！！！！
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
    while(cin>>n) {
        if (n==1) {                                 //一个数的特殊处理
            int tmp;
            cin>>tmp;
            if (tmp==1) cout<<n+1<<endl;           //不能输出0
            else cout<<tmp-1<<" "<<tmp+1<<endl;
            continue;
        }
        vector<int> v;int tmp=0;
   	 	while(n--) {
            cin>>tmp;
        	v.push_back(tmp);
    	}
        sort(v.begin(),v.end());
        int first=0,index=0;
        for (int i=1;i<v.size();i++) {
			if (v[i-1]!=v[i]-1) {
				if (first==0) {    //第一次缺失
                    index = v[i-1]+1;
                    if (index+1!=v[i]) {  //一个数填不上
                        first =2;
                    	break;
                    }
                    first=1;  //一个数能填上
                }
                else
	                first=2;
            }
        }
        if (first==0) {
            if (v[0]==1) cout<<v[v.size()-1]+1<<endl;
            else
            	cout<<v[0]-1<<" "<<v[v.size()-1]+1<<endl;
        }
        if (first==1) cout<<index<<endl; 
        if (first==2) cout<<"mistake"<<endl;
    }
    return 0;
}