/*****************************************************************
自守数是指一个数的平方的尾数等于该数自身的自然数。
例如：25^2 = 625，76^2 = 5776，9376^2 = 87909376。请求出n以内的自守数的个数

*********************************************************************/
//转成字符串，然后进行查找操作
#include<iostream>
#include<string>
using namespace std;
int help(int n){
    int ret=0;
    for (int i=0;i<n;i++){
        long long int m=i*i;
    	string s1=to_string(i);
   		string s2=to_string(m);
    	int pos = s2.size()-s1.size();
        if (s2.find(s1,pos)!=string::npos)
            ret++;
    } 
    return ret;
    
}
int main(){
	int n;
    while(cin>>n){
        cout<<help(n)<<endl;
    }
    return 0;
}