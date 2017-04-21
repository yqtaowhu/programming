// Date   : 2016.08.01
// Author : yqtao
// https://github.com/yqtaowhu
/********************************************************************************** 
* 
* You are climbing a stair case. It takes n steps to reach to the top.
* 
* Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
* 
*               
**********************************************************************************/

class Solution {
public:
    int climbStairs(int n) {
        int t1=1,t2=2;
        if (n==1||n==2) return n;
        int total=0;
        for (int i=3;i<=n;i++) {
            total=t1+t2;
            t1=t2;
            t2=total;
        }
        return total;
    }
};
