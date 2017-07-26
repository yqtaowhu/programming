

#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    while(cin>>n){
		int count=0,ret=0;
        while(n){
			if (n&1) {
                count++;
                ret=max(ret,count);
            }
            else {
                count=0;
            }
            n=n>>1;
        }
        cout<<ret<<endl;
    }
}