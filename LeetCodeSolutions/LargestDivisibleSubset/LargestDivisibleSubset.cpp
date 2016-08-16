// Date   : 2016.08.10
// Author : yqtao
// https://github.com/yqtaowhu
/**************************************************************************************************
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) 
of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]
**********************************************************************************************************/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int i,j,len=nums.size(),m=0,mi;
        vector<int> T(len,0);
        vector<int> son(len,0);
        sort(nums.begin(),nums.end());
        for(i=0;i<len;i++){
            for(j=i;j>=0;j--){
                if(nums[i]%nums[j]==0&&T[j]+1>T[i]){
                    T[i]=T[j]+1;
                    son[i]=j;
                }
            }
            if(T[i]>m){
                m=T[i];
                mi=i;
            }
        }
        vector<int> re;
        for(i=0;i<m;i++){
            re.insert(re.begin(),nums[mi]);
            mi=son[mi];
        }
        return re;
    }
};