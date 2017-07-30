输出7有关数字的个数，包括7的倍数，还有包含7的数字（如17，27，37...70，71，72，73...）的个数

输入描述:
一个正整数N。(N不大于30000)


#include<iostream>
#include<string>
using namespace std;

int help(int n){
    int ret=0;
	for (int i=1;i<=n;i++) {
        string s = to_string(i);
        if (s.find('7')!=string::npos||i%7==0)
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