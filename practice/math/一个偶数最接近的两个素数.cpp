/*****************************************************************
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，
本题目要求输出组成指定偶数的两个素数差值最小的素数对 
*********************************************************************/

#include<iostream>
#include<vector>
using namespace std;
//素数
bool help(int n){
    for(int i=2;i<=n/2;i++)
        if (n%i==0) return false;
    return true;
}
int main(){
    int n;
    while(cin>>n){
        int a=0,b=0;
		for (int i=2;i<=n/2;i++) {
            if (help(i)&&help(n-i)) {
                a=i;
                b=n-i;
            }
        }
        cout<<a<<endl;
        cout<<b<<endl;
    }
}