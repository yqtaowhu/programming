// Date   : 2016.10.06
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * Given a list of non negative integers, arrange them such that they form the largest number.
 * 
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 * 
 * Note: The result may be very large, so you need to return a string instead of an integer.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
 //elegant solution,using lambda function
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res="";
        if(nums.empty()) return res;
        sort(nums.begin(),nums.end(),[](const int& a,const int& b)
            {return to_string(a)+to_string(b)>to_string(b)+to_string(a);});
        for (auto c:nums) res+=to_string(c);
        return (nums[0]==0) ? "0" : res;
    }
};
