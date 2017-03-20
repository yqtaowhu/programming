/******************************************************************************************************
输入多行，先输入要计算乘法的矩阵个数n，每个矩阵的行数，列数，总共2n的数，最后输入要计算的法则

输出描述:
输出需要进行的乘法次数

输入例子:
3
50 10
10 20
20 5
(A(BC))

输出例子:
3500
****************************************************************************************************/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){   
    int n;    
    string s; 
    while(cin>>n){  
        int a[n][2]; 
        for(int i=0;i<n;++i)   
            cin>>a[i][0]>>a[i][1];  
		//p 左括号，q右括号，k第几个矩阵
        int k=0,sum=0;       
        int p=0,q=0;       
        vector<int> vec;    
        cin>>s;       
        for(int i=0;i<s.length();++i){    
            if(s[i]!=')'){              
                if(s[i]=='(')              
                    p++;           
                else               
                    vec.push_back(k++);   
            }          
            else{              
                if(++q>p)break;  //测试用例中有‘)’个数多于‘(’个数的情况，故加入该判断语句。           
                int y=vec.back();             
                vec.pop_back();             
                int x=vec.back();             
                vec.pop_back();               
                sum+=a[x][0]*a[x][1]*a[y][1];    
                a[x][1]=a[y][1];             
                vec.push_back(x);         
            }    
        }     
        cout<<sum<<endl;  
    }    
    return 0;
}