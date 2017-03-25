/*****************************************************************************************
链接：https://www.nowcoder.com/questionTerminal/af709ab9ca57430886632022e543d4c6
来源：牛客网
小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？ 
输入描述:
 输入包含多组测试数据。
 对于每组测试数据：
 N - 本组测试数据有n个数
 a1,a2...an - 需要计算的数据
 保证:
 1<=N<=100000,0<=ai<=INT_MAX.

输出描述:
对于每组数据，输出两个数，第一个数表示差最小的对数，第二个数表示差最大的对数。

输入例子:
6
45 12 45 32 5 6
输出例子:
1 2
**************************************************************************************************/
//任意两个数字都可一起组合的！！！
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){    
    int n;   
    while (cin >> n){
        if (n < 2){   
            cout << 0 << ' ' << 0 << endl;  
            continue;       
        }       
        if (n == 2){    
            cout << 1 << ' ' << 1 << endl;   
            continue;      
        }       
        //3个数以上的情况   
        vector<int> data;      
        while (n--){         
            int temp;           
            cin >> temp;        
            data.push_back(temp);  
        }       
        int length = data.size();  
        sort(data.begin(), data.end());    
        //先求最小的，肯定是相邻的相减得到   
        int min_val = abs(data[1] - data[0]);   
        for (int i = 2; i < length; ++i){     
            int cur = (data[i] - data[i - 1]);      
            if (cur < min_val) 
                min_val = cur;      
        }        //统计最小的数目    
        int min_count = 0;        
        if (min_val == 0){//有相同大小的数子，统计个数，用组合求对数 
            for (int i = 1; i < length; ++i)           
            {               
                int j = i - 1;     
                while (j >= 0 && data[i] == data[j]){   
                    ++min_count;               
                    --j;              
                }          
            }      
        }       
        else {        
            for (int i = 1; i < length; ++i){   
                int cur = (data[i] - data[i - 1]);  
                if (cur == min_val)             
                    ++min_count;          
            }      
        }  //求差最大的对数：最小的个数*最大的个数（如果最大的不等于最小的）   
        int max_val = data[length - 1] - data[0];    
        int max_count = 0;      
        int a, b;     
        a = b = 0;   
        for (int i = 0; i < length; ++i){     
            if (data[i] == data[0])        
                ++a;    
        }       
        for (int i = length - 1; i >= 0; --i){   
            if (data[i] == data[length - 1]) 
                ++b;    
        }      
        if (max_val == 0)//当最大等于最小，即数据全部一样eg. 1 1 1 1时，显然 4*4是不对的   
            max_count = length*(length - 1) / 2;     
        else           
            max_count = a*b;      
        cout << min_count << ' ' << max_count << endl;   
    }    
    return 0;
}