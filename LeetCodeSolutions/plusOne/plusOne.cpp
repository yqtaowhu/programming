// Author : yqtao
// Date   : 2016-09-13
// Email  : yqtao@whu.edu.cn

/********************************************************************************** 
* 
* Given a non-negative number represented as an array of digits, plus one to the number.
* 
* The digits are stored such that the most significant digit is at the head of the list.
*               
**********************************************************************************/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        int len=digits.size();
        vector<int>result(len);
        while (len>0)  {
            int sum=carry+digits[len-1];
            result[len-1]=sum%10;
            carry=sum/10;
            len--;
        }
        if (carry>0)
            result.insert(result.begin(),1);
         return result;
    }
};
