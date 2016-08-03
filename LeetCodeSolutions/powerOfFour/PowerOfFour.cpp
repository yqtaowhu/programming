// Date   : 2016.08.03
// Author : yqtao
// https://github.com/yqtaowhu


/*************************************************************************************** 
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a power 
 * of 4.
 * 
 * Example:
 * Given num = 16, return true.
 * Given num = 5, return false.
 * 
 * Follow up: Could you solve it without loops/recursion?
 * 
 * Credits:Special thanks to @yukuairoy  for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/
 //#Iterative Solution#
	bool isPowerOfFour(int num) {
        if (num>0)
            while (num%4==0) num/=4;
        return num==1;
    }
	
//# operator &#
	bool isPowerOfFour(int num) {
        if (num<0) return false;
        if (num&(num-1)) return false;   //judge power 2;
        return num&0x55555555; 
    }


