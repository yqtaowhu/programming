// Date   : 2016.08.04
// Author : yqtao
// https://github.com/yqtaowhu


/********************************************************************************** 
* Implement pow(x, n).           
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

class Solution {
public:
    double myPow(double x, int n) {
	unsigned exp = n > 0 ? n : -n;// careful ,it must be unsigned
	double result = 1.0;
	while (exp) {
		if (exp & 1) {
			result *= x;
		}
		exp >>= 1;
		x *= x;
	}
	return n > 0 ? result : 1 / result;
}
};
