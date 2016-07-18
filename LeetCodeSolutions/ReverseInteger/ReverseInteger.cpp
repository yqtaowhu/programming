//Author: yqtao
//Email : yqtao@whu.edu.cn
//Date  :2016.7.5
/**********************************************************************************
*
* Reverse digits of an integer.
*
* Example1: x =  123, return  321
* Example2: x = -123, return -321
*
*first ,we should think the number  over/underflow,it is very importent;
*then ,we need not to think the number is a negtive,like -123,it do not like string to integer
*so we can easy to deal the problems,
**********************************************************************************/
#include<iostream>
#include <vector>
using namespace std;
int reverse(int x) {
	int y = 0;
	int n;
	while (x != 0) {
		n = x % 10;
		//Checking the over/underflow.
		//Actually, it should be y>(INT_MAX-n)/10, but n/10 is 0, so omit it.
		if (y > INT_MAX / 10 || y < INT_MIN / 10) {
			return 0;
		}
		y = y * 10 + n;
		x /= 10;
	}
	return y;
}
//Actually,we can using long long is a 64bit numbers ,it cant to over/underflow
//for example,it is so smart;
int reverse1(int x) {
	long long res = 0;
	while (x) {
		res = res * 10 + x % 10;
		x /= 10;
	}
	return (res<INT_MIN || res>INT_MAX) ? 0 : res;
}
int main()
{
	int x1 =-123,x2 = 1534236469,x3 = 4,x4 = -12340;
	cout << reverse1(x1) << endl;
	cout << reverse1(x2) << endl;
	cout << reverse1(x3) << endl;
	cout << reverse1(x4) << endl;
}