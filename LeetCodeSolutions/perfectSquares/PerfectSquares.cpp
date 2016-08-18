// Date   : 2016.08.18
// Author : yqtao
// https://github.com/yqtaowhu

/*************************************************************************************** 
 *
 * Given a positive integer n, find the least number of perfect square numbers (for 
 * example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 
 * because 13 = 4 + 9.
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 *               
 ***************************************************************************************/

class Solution 
{
public:
  int numSquares(int n) {
	if (n <= 0) return 0;
	// cntPerfectSquares[i] = the least number of perfect square numbers 
	// which sum to i. Note that cntPerfectSquares[0] is 0.
	vector<int> cntPerfectSquares(n + 1, INT_MAX);
	cntPerfectSquares[0] = 0;
	for (int i = 1; i <= n; i++)
	// For each i, it must be the sum of some number (i - j*j) and 
	// a perfect square number (j*j).
		for (int j = 1; j*j <= i; j++)
			cntPerfectSquares[i] =min(cntPerfectSquares[i], cntPerfectSquares[i - j*j] + 1);
	return cntPerfectSquares.back();
}
};

