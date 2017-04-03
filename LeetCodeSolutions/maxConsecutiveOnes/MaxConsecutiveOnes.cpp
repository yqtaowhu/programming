class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n=nums.size(),ret=0,count=0;
        for(int i=0;i<n;){
            if(nums[i]==1){
                while(nums[i]==1) {
                    count++;
                    ret=max(ret,count);
                    i++;
                }
            }
            else {
                i++;
                count=0;
            }
                
        }
        return ret;
    }
};