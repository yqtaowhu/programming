//Author: yqtao
//Email : yqtao@whu.edu.cn
//Date  :2016.7.5
/**************************************
* Implement atoi to convert a string to an integer.
* 实现一个字符串到数字的转换
******************************/
/*
   this problems is difficult at should check  INT_MAX (2147483647) or INT_MIN (-2147483648) 
   it can be very complex very we have no idea;
   for this have two solutions to do:
*/


#include<iostream>
#include<string>
#include<cctype>
using namespace std;
//solution 1:
int myAtoi(string str)
{
	int len = str.size(), i = 0;
	if (len < 1) return 0;
	while (isspace(str[i])) i++;  //skip the space
	int indicator = 1;  
	if (str[i] == '+' || str[i] == '-') {
		indicator = (str[i++] == '-') ? -1 : 1;
	}
	long long  result = 0;       //using long long is very simple to solve 
	while ('0' <= str[i] && str[i] <= '9')   //can also use isdigit(s[i])
	{
		int digit = str[i] - '0';
		result = result * 10 + digit;
		if (result*indicator >= INT_MAX) return INT_MAX;   //you see it is very easy
		if (result*indicator <= INT_MIN) return INT_MIN;
		i++;
	}
	return result*indicator;  
}
//solution 2
int myAtoi1(string str)
{
	int len = str.size(), i = 0;
	if (len < 1)
		return 0;
	while (isspace(str[i])) i++;  //skip the space
	bool neg = false;
	if (str[i] == '-' || str[i] == '+') {
		neg = (str[i] == '-');
		i++;
	}
	int  result = 0;
	while (isdigit(str[i]))
	{
		int digit = str[i] - '0';
		if (neg) {
			if (-result < (INT_MIN + digit) / 10) {    //it can be difficult to understand
				return INT_MIN;
			}
		}
		else {
			if (result >(INT_MAX - digit) / 10) {
				return INT_MAX;
			}
		}
		result = result * 10 + digit;
		i++;
	}
	return  neg ? -result : result;
}

int main()
{
	string s = "  2147483648   ";
	cout << myAtoi(s)<< endl;
}