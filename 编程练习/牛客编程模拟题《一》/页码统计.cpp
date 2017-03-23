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