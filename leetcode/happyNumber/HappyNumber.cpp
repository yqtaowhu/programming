// Date   : 2016.08.04
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with any positive integer, 
 * replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 
 * (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this 
 * process ends in 1 are happy numbers.
 * 
 * Example: 19 is a happy number
 * 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 * Credits:Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
//very quikly ,just using 0 ms 
//reference :https://en.wikipedia.org/wiki/Happy_number
//just know 1 is happy number,and 4 is not 
class Solution {
public:
     bool isHappy(int n) {
            int num=0;
            while(n!=1&&n!=4) {
                while(n) {
                    num += (n%10) * (n%10);
                    n/=10;
                }
                n=num;num=0;
            }
            return 1==n;
        }
};
//recursion , the idea is simple to above
class Solution {
public:
     bool isHappy(int n) {
        if (n==1) return true;
        if (n==4) return false;
        int num=0;
        while (n) {
            int t=n%10;
            num+=t*t;
            n/=10;
        }
        return isHappy(num);
    }
};
//using map
//if you dont know 4 is unhappy,just using it 
class Solution {
public:
    bool isHappy(int n) {
        int num=0;
        unordered_map<int,bool> table; 
        table[n]=1;
        while(n!=1)
        {
            while(n)
            {
                num += (n%10) * (n%10);
                n/=10;
            }
            if(table[num]) break; //is equal to pre number ,break ,if not do ,it will always iterator.
            else table[num]=1;    //this is why using a map to control.
            n=num;num=0;
        }
        return 1==n;
    }
};