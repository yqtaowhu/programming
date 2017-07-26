/*******************************************************************************
给定一个字符串，请你将字符串重新编码，将连续的字符替换成“连续出现的个数+字符”。
比如字符串AAAABCCDAA会被编码成4A1B2C1D2A。
*********************************************************************************/
#include<iostream>
#include<string>
using namespace std;
string help(string s){
    if(s.size()==0) return "";
    int count=1;char first=s[0];
    string res="";
    for (int i=1;i<s.size();i++) {
        if (s[i]==first) count++;
        else {
            res+=to_string(count)+first;
            count=1;
            first=s[i];
        }
    }
    res+=to_string(count)+first;
    return res;
}
int main(){
    string s;
    while(cin>>s){
        cout<<help(s)<<endl;
    }
    return 0;
}