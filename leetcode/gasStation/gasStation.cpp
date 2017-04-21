// Date   : 2016.09.24
// Author : yqtao
// https://github.com/yqtaowhu
//reference:https://discuss.leetcode.com/topic/5088/my-ac-is-o-1-space-o-n-running-time-solution-does-anybody-have-posted-this-solution
/********************************************************************************** 
* 
* There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
* 
* You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to 
* its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
* 
* Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
* 
* Note:
* The solution is guaranteed to be unique.
* 
*               
**********************************************************************************/
//end is the next point to reach
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

       int start = gas.size()-1;
       int end = 0;
       int sum = gas[start] - cost[start];
       while (start > end) {
          if (sum >= 0) {
             sum += gas[end] - cost[end];
             ++end;
          }
          else {
             --start;
             sum += gas[start] - cost[start];   //while sum<0,just start--,and find this can make sum>=0.complement the end .
          }
       }
       return sum >= 0 ? start : -1;
    }
};
