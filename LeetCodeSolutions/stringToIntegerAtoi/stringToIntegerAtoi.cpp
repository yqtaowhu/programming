// Date   : 2016.08.04
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Implement atoi to convert a string to an integer.
* 
* Hint: Carefully consider all possible input cases. If you want a challenge, 
*       please do not see below and ask yourself what are the possible input cases.
* 
* Notes: 
*   It is intended for this problem to be specified vaguely (ie, no given input specs). 
*   You are responsible to gather all the input requirements up front. 
* 
* 
* Requirements for atoi:
* 
* The function first discards as many whitespace characters as necessary until the first 
* non-whitespace character is found. Then, starting from this character, takes an optional 
* initial plus or minus sign followed by as many numerical digits as possible, and interprets 
* them as a numerical value.
* 
* The string can contain additional characters after those that form the integral number, 
* which are ignored and have no effect on the behavior of this function.
* 
* If the first sequence of non-whitespace characters in str is not a valid integral number, 
* or if no such sequence exists because either str is empty or it contains only whitespace 
* characters, no conversion is performed.
* 
* If no valid conversion could be performed, a zero value is returned. If the correct value 
* is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) 
* is returned.
*               
**********************************************************************************/

#include <iostream>
#include <vector>
#include<queue>
#include<string>
using namespace std;
bool isHappy(int n) {
	if (n <= 0) return false;
	if (n == 1) return true;
	int result = 0;
	while (n) {
		int digit = n % 10;
		result += digit*digit;
		n /= 10;
	}
	return isHappy(result);
}

int main(int argc, char** argv) {


	cout << isHappy(2) << endl;
	return 0;
}