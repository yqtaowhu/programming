/***************************************************************
编写一个程序，将输入字符串中的字符按如下规则排序。
规则1：英文字母从A到Z排列，不区分大小写。
      如，输入：Type 输出：epTy
规则2：同一个英文字母的大小写同时存在时，按照输入顺序排列。
    如，输入：BabA 输出：aABb
规则3：非英文字母的其它字符保持原来的位置。
    如，输入：By?e 输出：Be?y
样例：
    输入：
   A Famous Saying: Much Ado About Nothing(2012/8).
    输出：
   A aaAAbc dFgghh: iimM nNn oooos Sttuuuy (2012/8).
**********************************************************/
#include<vector>
#include<iostream>
#include<string> 
using namespace std;
int main(){   
    string s;   
    vector<char> tempChar;  
    while(getline(cin,s)) {   
        tempChar.clear();   
        int len = s.size();   
        //分别找英文字母
        for(int j=0; j<26; j++) {      
            for(int i=0; i<len; i++) {              
                if(s[i]-'a'==j||s[i]-'A'==j) {                  
                    tempChar.push_back(s[i]);  
                }           
            }       
        }       
        for(int i=0,k=0;(i<len)&&k<tempChar.size();i++) {   
            //是字母是，进行替换
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))   
                s[i]=tempChar[k++];    
        }       
        cout<<s<<endl; 
    }    
    return 0;
}