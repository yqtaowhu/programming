// Date   : 2016.07.31
// Author : yqtao
// https://github.com/yqtaowhu

/**********************************************************************************
*
* Given an array S of n integers, find three integers in S such that the sum is
* closest to a given number, target. Return the sum of the three integers.
* You may assume that each input would have exactly one solution.
*
*     For example, given array S = {-1 2 1 -4}, and target = 1.
*
*     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*
*
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INT_MAX 2147483647
int threeSumClosed(vector<int>&num,int target)
{
    sort(num.begin(), num.end());//首先进行排序
    int n = num.size();
    int distance = INT_MAX;
    int result;
    for (int i = 0; i < n - 2; i++)// 因为三个数，所以第一个数最大只能为len-3
    {
        //去掉重复值,这里一定要注意，i如果与前一个i所在值相同，则
        //不必计算了，直接另i++
        //不能写成num[i]==num[i+1]

        if (i > 0 && num[i - 1] == num[i])
            continue;
        int a = num[i];
        int low = i + 1;
        int high = n - 1;
        while (low < high)
        {
            int b = num[low];
            int c = num[high];
            int sum = a + b + c;
            if (sum - target == 0)//即两者相等
                return target;
            else
            {//主要语句，此主要是找到最小的distance
                if (abs(sum - target) < distance)
                {
                    distance = abs(sum - target);
                     result = sum;
                }
                if (sum - target > 0)
                {
                    while (high < low&&num[high] == num[high - 1])
                        high--;
                    high--;
                }
                else 
                {
                    while (low < high&&num[low] == num[low + 1])
                        low++;
                    low++;
                }
            }

        }
    }
    return result;
}
int main()
{
    vector<int>num = { -1, 2, 1, -4 };
    cout << threeSumClosed(num, 1);
    return 0;
}