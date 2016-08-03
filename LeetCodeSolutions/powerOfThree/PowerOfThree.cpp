// Date   : 2016.08.03
// Author : yqtao
// https://github.com/yqtaowhu

/*************************************************************************************** 
 *
 * Given an integer, write a function to determine if it is a power of three.
 * 
 *     Follow up:
 *     Could you do it without using any loop / recursion?
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 *               
 ***************************************************************************************/
//#Recursive Solution#
 bool isPowerOfThree(int n) {
        if (n<=0) return false;
        if (n==1) return true;
        return (n%3==0)&&isPowerOfThree(n/3);
    }
//#Iterative Solution#
 bool isPowerOfThree(int n) {
       if (n>1)
          while (n%3==0) n/=3;
       return n==1;
    }
//math solution
  bool isPowerOfThree(int n) {
        return n > 0 && (1162261467 % n == 0);  //maxPowerOfThree = 1162261467
    }
//
bool isPowerOfThree(int n) {
        double logRes = log10(n)/log10(3); 
        return (logRes - int(logRes) == 0);
    }