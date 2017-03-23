/*****************************************************************************************
如果一个单词通过循环右移获得的单词，我们称这些单词都为一种循环单词。 例如：picture 和 turepic 就是属于同一种循环单词。 现在给出n个单词，需要统计这个n个单词中有多少种循环单词。 
输入描述:
输入包括n+1行：

第一行为单词个数n(1 ≤ n ≤ 50)

接下来的n行，每行一个单词word[i]，长度length(1 ≤ length ≤ 50)。由小写字母构成


输出描述:
输出循环单词的种数

输入例子:
5
picture
turepic
icturep
word
ordw

输出例子:
2
*****************************************************************************************/
//暴力的方法
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
	int n;
    while(cin>>n) {
		string s;
        int count=0;
        map<string,int>m;
        while(n--){
			cin>>s;
            if (m.find(s)==m.end()) {
                count++;
                m[s]=1;
				//枚举所有的可能，加入map中
				for (int i=1;i<s.size();i++) {
					string tmp = s.substr(i)+s.substr(0,i);
                    m[tmp]=1;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
//set的方法，加入最小的组合
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
//calc的目的是计算这个字符串的最小的组成排序
string calc(string x) {
    vector<string> v;
    int n=x.size();
	//共有n中组合，因为有n个长度
    for (int i=0;i<n;i++) {
        string temp=x;
        for (int j=0;j<n;j++) {
            temp[j]=x[(i+j)%n];
        }
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
	//最小的组合
    return v[0];
}
int main() {
    int n;cin>>n;
    string x;	
    set<string> s;
    for (int i=0;i<n;i++) {
    	cin>>x;
    	string y=calc(x);
    	s.insert(y); //插入最小的，每一个都转成最小的，因为set没有重复的
    }
    cout<<s.size();
}