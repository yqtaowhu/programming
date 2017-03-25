
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        if(s.size()<=1) {
            cout<<s<<endl;
            continue;
        }
        for(int i=1;i<s.size();i++){
            char tmp = s[i];
            int j;
            for(j=i-1;j>=0&&(s[j]>='A'&&s[j]<='Z')&&!(tmp>='A'&&tmp<='Z');j--) {
                s[j+1] = s[j];
            }
            s[j+1]=tmp;
             
        }
        cout<<s<<endl;
    }
    return 0;
}