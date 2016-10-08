// Source : https://leetcode.com/problems/count-primes/
// Author : Hao Chen
// Date   : 2015-06-09

/********************************************************************************** 
 * 
 * Description:
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
 * 
 *   Let's start with a isPrime function. To determine if a number is prime, we need to check if 
 *   it is not divisible by any number less than n. The runtime complexity of isPrime function 
 *   would be O(n) and hence counting the total prime numbers up to n would be O(n2). Could we do better?
 *   
 *   As we know the number must not be divisible by any number > n / 2, we can immediately cut the total 
 *   iterations half by dividing only up to n / 2. Could we still do better?             
 **********************************************************************************/
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1,true);
        int count=0;
        for (int i=2;i<n;i++) {
            if (prime[i]) {
                count++;
                for (int j=2;j*i<n;j++)    //删除所有素数的倍数
                    prime[j*i]=false;
            }
        }
        return count;
    }
};
