



#include<iostream>
using namespace std;
int gcd(int a,int b){
	if (b==0)
        return a;
    return gcd(b,a%b);
}
int gcd1(int a,int b){
    while(a%b){
        int tmp = a;
        a = b;
        b = tmp%b;
    }
    return b;
}
int main(){
    int a,b;
    while(cin>>a>>b){
		cout<<a*b/gcd1(a,b)<<endl;
    }
}