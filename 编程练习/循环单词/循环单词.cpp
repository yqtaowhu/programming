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
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
string calc(string x) {
    vector<string> v;
    int n=x.size();
    for (int i=0;i<n;i++) {
        string temp=x;
        for (int j=0;j<n;j++) {
            temp[j]=x[(i+j)%n];
        }
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    return v[0];
}
int main() {
    int n;cin>>n;
    string x;	
    set<string> s;
    for (int i=0;i<n;i++) {
    	cin>>x;
    	string y=calc(x);
    	s.insert(y);
    }
    cout<<s.size();
}