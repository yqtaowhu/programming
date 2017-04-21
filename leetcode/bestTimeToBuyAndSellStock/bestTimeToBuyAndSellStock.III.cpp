// Date   : 2016.09.21
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* Design an algorithm to find the maximum profit. You may complete at most two transactions.
* 
* Note:
* You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*               
**********************************************************************************/
//difficult to understand
//just test : 7 1 4 5 2 7.
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int sell1 = 0, sell2 = 0, buy1 = INT_MIN, buy2 = INT_MIN;
        for(int i = 0; i < n; i++) {
            buy1 = max(buy1, -prices[i]);                //buy1是我们买入时欠的钱，假设我们没有钱
            sell1 = max(sell1, buy1 + prices[i]);        //即能获得最大利润，在测试时为   1    7 获得最大利润
            buy2 = max(buy2, sell1 - prices[i]);         
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
}; 
