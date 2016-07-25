// Date   : 2016.07.25
// Author : yqtao
// https://github.com/yqtaowhu

/*************************************************************************************** 
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For 
 * example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 * 
 * Note that 1 is typically treated as an ugly number.
 * 
 *   The naive approach is to call isUgly for every number until you reach the nth one. 
 * Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
 *
 *   An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
 *
 *   The key is how to maintain the order of the ugly numbers. Try a similar approach 
 * of merging from three sorted lists: L1, L2, and L3.
 *
 *   Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 
 * * 5).           
 ***************************************************************************************/
 /*
 *We have an array k of first n ugly number. We only know, at the beginning, the first one, which is 1. Then
*k[1] = min( k[0]x2, k[0]x3, k[0]x5). The answer is k[0]x2. So we move 2's pointer to 1. Then we test:
*k[2] = min( k[1]x2, k[0]x3, k[0]x5). And so on. Be careful about the cases such as 6, 
*in which we need to forward both pointers of 2 and 3.
*x here is multiplication.
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n<=0) return 0;
        if (n==1) return 1;
        vector<int>k(n);
        k[0]=1;
        int t2=0,t3=0,t5=0;
        for (int i=1;i<n;i++) {
            k[i]=min(k[t2]*2,min(k[t3]*3,k[t5]*5));
            if (k[i]==k[t2]*2) t2++;
            if (k[i]==k[t3]*3) t3++;
            if (k[i]==k[t5]*5) t5++;
        }
        return k[n-1];
    }
};
