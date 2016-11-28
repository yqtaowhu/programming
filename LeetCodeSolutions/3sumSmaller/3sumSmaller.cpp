/**************************************************************************************************************
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n 
that satisfy the condition nums[i] + nums[j] + nums[k] < target.
For example, given nums = [-2, 0, 1, 3], and target = 2.
Return 2. Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]
******************************************************************************************************************/

int threeSumSmaller(vector<int>&nums, int target){  
    int size = nums.size();  
    sort(nums.begin(),nums.end());  
    int cnt = 0;  
    for(int i = 0;i < size-2;i++){  
        int j = i+1,k = size - 1;  
        while(j < k){  
           int sum = nums[i] + nums[j] + nums[k];             
           if(sum < target)cnt++;  
           k--;    //仅仅移动此指针
        }           
    }  
    return cnt;  
}  