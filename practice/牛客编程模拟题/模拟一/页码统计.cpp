#include <iostream>
#include <vector>
using namespace std;
long long counteach(long long n, int i)  //统计数字i出现个数
{
	long long iCount = 0;
	long long iFactor = 1;
	long long iLowerNum = 0;
	long long iCurrNum = 0;
	long long iHigherNum = 0;

	while (n / iFactor != 0)
	{
		iLowerNum = n - (n / iFactor)*iFactor;
		iCurrNum = (n / iFactor) % 10;
		iHigherNum = n / (iFactor * 10);

		if (iCurrNum<i)
			iCount += iHigherNum*iFactor;
		else if (i == iCurrNum)
			iCount += iHigherNum*iFactor + iLowerNum + 1;
		else if (iCurrNum>i)
			iCount += (iHigherNum + 1)*iFactor;
		//处理0的个数
		//若n为1位数，比如本来是1 2 3 4 5 6 ，之前处理成 0 1 2 3 4 5 6,多加了1个0
		//若n为2位数，比如本来是1 2 3 4 5 6 7 8 9 10 11 12，之前处理成 00 01 02 ...09 10 11 12,多加了1+10个0
		//若n为3位数，比如本来是1 2 3 4 ... 115，之前处理成000 001 002 ...009 010 011...099 100...115，多加了1+10+100个0
		//因此需要在每层循环中减去多计算的0的个数
		if (0 == i)
			iCount -= iFactor;

		iFactor *= 10;
	}
	return iCount;
}
vector<long long> count(long long n)    //依次统计0~9
{
	vector<long long>res(10, 0);
	for (int i = 0; i<10; i++){
		res[i] += counteach(n, i);
	}
	return res;
}
int main()
{
	long long n;
	cin >> n;
	vector<long long>res = count(n);
	for (int i = 0; i < res.size(); i++){
		i == 0 ? cout << res[i] : cout << " " << res[i];
	}
	return 0;
}

///////////////////////////////////
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