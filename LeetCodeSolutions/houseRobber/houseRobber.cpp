// Date   : 2016.08.04
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * You are a professional robber planning to rob houses along a street. Each house has 
 * a certain amount of money stashed, the only constraint stopping you from robbing 
 * each of them is that adjacent houses have security system connected and it will 
 * automatically contact the police if two adjacent houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of each house, 
 * determine the maximum amount of money you can rob tonight without alerting the police.
 * 
 *               
 **********************************************************************************/
//DP Solution  
//Here is the DP formula that leads to the right answer:
//M(k) = money at the kth house
//P(0) = 0
//P(1) = M(1)
//P(k) = max(P(k−2) + M(k), P(k−1))
class Solution {
public:
    int rob(vector<int>& nums) {
       int len=nums.size();
       if (len==0) return 0;
       if (len==1) return nums[0];
       vector<int> p(len);
       p[0]=nums[0];
       p[1]=max(p[0],nums[1]);
       for (int i=2;i<len;i++) {
           p[i]=max(p[i-2]+nums[i],p[i-1]);
       }
       return p[len-1];
    }
};
//DP O(1) SPACE
class Solution {
public:
    int rob(vector<int>& nums) {
       int len=nums.size();
       if (len==0) return 0;
       if (len==1) return nums[0];
       int pre=nums[0];
       int preNext=max(nums[0],nums[1]);
       if (len==2) return preNext;
       int cur=0;
       for (int i=2;i<len;i++) {
           cur=max(pre+nums[i],preNext);
           pre=preNext;
           preNext=cur;
       }
       return cur;
    }
};