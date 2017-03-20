/*********************************************************************************************
现有一组砝码，重量互不相等，分别为m1,m2,m3…mn；
每种砝码对应的数量为x1,x2,x3...xn。现在要用这些砝码去称物体的重量，问能称出多少中不同的重量。
 
注：
称重重量包括0
 
方法原型：public static int fama(int n, int[] weight, int[] nums)


输入描述:
输入包含多组测试数据。

对于每组测试数据：

第一行：n --- 砝码数(范围[1,10])

第二行：m1 m2 m3 ... mn --- 每个砝码的重量(范围[1,2000])

第三行：x1 x2 x3 .... xn --- 每个砝码的数量(范围[1,6])


输出描述:
利用给定的砝码可以称出的不同的重量数

输入例子:
2
1 2
2 1

输出例子:
5
***************************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){    
    int n;    
    while(cin>>n){  
        vector<int> weight(n); 
        vector<int> num(n);      
        for(int i=0;i<n;i++)        
            cin>>weight[i];     
        for(int i=0;i<n;i++)       
            cin>>num[i];       
        vector<int> ans;  
        //将第一个砝码能称出的所有质量入队。
        for(int i=0;i<=num[0];i++){   
            ans.push_back(i*weight[0]);       
        }
        //前多少个砝码j=1表示第二个砝码
        for(int j=1;j<n;j++){   
            int size=ans.size();
            //该质量的砝码数,1,2..
            for(int i=1;i<=num[j];i++)   
                for(int m=0;m<size;m++){    
                    //添加i个j砝码,看有没有重复
                    if(find(ans.begin(),ans.end(),ans[m]+i*weight[j])==ans.end())       
                        ans.push_back(ans[m]+i*weight[j]);      
                }       
        }        
        cout<<ans.size()<<endl;   
    }  
    return 0;
}