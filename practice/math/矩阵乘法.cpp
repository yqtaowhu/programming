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
                    vec.push_back(k++); //第几个数字   
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
// 计算矩阵相乘
#include<iostream>
#include<vector>
using namespace std;
void getMat(vector<vector<int>>& v) {  
    for (int i = 0; i < v.size(); i++)    
        for (int j = 0; j < v[0].size(); j++)  
            cin >> v[i][j];}
int main() {  
    int m, n, k;    
    while (cin >> m >> n >> k) {  
        vector<vector<int>> A(m, vector<int>(n, 0));   
        vector<vector<int>> B(n, vector<int>(k, 0));   
        vector<vector<int>> res(m, vector<int>(k, 0));  
        getMat(A);        
        getMat(B);     
		//核心程序
        for (int i = 0; i < m; i++)  
            for (int j = 0; j < k; j++)  
                for (int l = 0; l < n; l++)  
                    res[i][j] += A[i][l] * B[l][j]; 
        for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[0].size(); j++) {
				j == 0 ? cout << res[i][j] : cout << " " << res[i][j];
			}
			cout << endl;
		}
    }
}