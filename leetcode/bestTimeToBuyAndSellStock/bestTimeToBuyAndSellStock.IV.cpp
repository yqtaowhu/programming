// Date   : 2016.09.21
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* Design an algorithm to find the maximum profit. You may complete at most k transactions.
* 
* Note:
* You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
* 
* Credits:Special thanks to @Freezen for adding this problem and creating all test cases.
*               
**********************************************************************************/
//reference:https://discuss.leetcode.com/topic/8984/a-concise-dp-solution-in-java
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int size = (int)prices.size();
        if (k==0||size<2) {
            return 0;
        }
        if (k>size/2) {
            int sum = 0;
            for(int i = 1;i < size;i++){
                if(prices[i] > prices[i-1]){
                    sum += prices[i] - prices[i-1];
                }
            }
            return sum;
        }
        vector<int> buy(k,INT_MIN);
        vector<int> sell(k,0);
        for (int i=0; i<size; i++) {
            for (int j=k-1; j>=0; j--) {
                sell[j]=max(sell[j],buy[j]+prices[i]);
                buy[j]=max(buy[j],(j>0?sell[j-1]:0)-prices[i]);
            }
        }
        return sell[k-1];
    }
};
