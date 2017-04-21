// Date   : 2016.08.05
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
* design an algorithm to find the maximum profit.
*               
**********************************************************************************/
/*
Input: [7, 1, 5, 3, 6, 4]
Output: 5
this mean should buy at 1 and sell at 6 is maxProfit.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro=0,minPrice=INT_MAX;
        for (int i=0;i<prices.size();i++) {
            minPrice=min(prices[i],minPrice);    	//get the minPrice
            maxPro=max(prices[i]-minPrice,maxPro);  //compare 
        }
        return maxPro;
    }
};
