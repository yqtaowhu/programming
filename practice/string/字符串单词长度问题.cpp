//求最后一个单词的长度
//从后往前是一种非常简单的思路
#include<iostream>
#include<string>
using namespace std;
int lengthOfLastWord(string s) {
       int i=s.size()-1,len=0;
       while (s[i]==' '&&i>=0) i--;    //去掉最后的0
       while (s[i]!=' '&&i>=0) {
           i--;len++;
       }
       return len;
    }
int main(){
    string str;
    while(getline(cin,str)){
       cout<<lengthOfLastWord(str)<<endl;  
    }
}