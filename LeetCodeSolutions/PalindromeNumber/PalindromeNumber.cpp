// Author : yqtao
// Date   : 2016-7-3
// Email  : yqtao@whu.edu.cn
/**********************************************************************************
*
* Determine whether an integer is a palindrome.Do this without extra space.
*
*
* Some hints :
*
* Could negative integers be palindromes ? (ie, -1)
*
* If you are thinking of converting the integer to string, note the restriction of using extra space.
*
* You could also try reversing an integer.However, if you have solved the problem "Reverse Integer",
*you know that the reversed integer might overflow.How would you handle such case ?
*
* There is a more generic way of solving this problem.
*
*
********************************************************************************/

#include<iostream>
using namespace std;
//Solutin 1
bool isPalindrome(int x) {
	if (x < 0 || (x != 0 && x % 10 == 0)) {
		return false;
	}
	long long result = 0;   //using long long it can not be overflow
	int temp = x;
	while (temp)      //revere the num;
	{
		result = result * 10 + temp % 10;
		temp /= 10;
		if (result>INT_MAX)    //if overflow ,it must be return false
			return false;
	}
	return x ==result;
}
//Solutin 2 
bool isPalindrome1(int x) {
	if (x < 0 || (x != 0 && x % 10 == 0)) {
		return false;
	}
	int half = 0;    
	while (x > half) {        
		half = half * 10 + x % 10;
		x /= 10;
	}
	if (half == x || half / 10 == x) {
		return true;
	}
	return false;
}
int main()
{
	cout << boolalpha << isPalindrome(121) << endl;
}