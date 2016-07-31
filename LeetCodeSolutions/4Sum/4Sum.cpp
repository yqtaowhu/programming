// Date   : 2016.07.31
// Author : yqtao
// https://github.com/yqtaowhu
/**********************************************************************************
*
* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
* Find all unique quadruplets in the array which gives the sum of target.
*
* Note:
*
* Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
* The solution set must not contain duplicate quadruplets.
*
*     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
*
*     A solution set is:
*     (-1,  0, 0, 1)
*     (-2, -1, 1, 2)
*     (-2,  0, 0, 2)
*
*
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>&num, int target);
vector<vector<int>> fourSum(vector<int>&num, int target)
{
    vector<vector<int>> result;
    if (num.size() < 4) return result;
    sort(num.begin(), num.end());//首先进行排序
    for (int i = 0; i < num.size() - 3; i++)
    {
        if (i > 0 && num[i - 1] == num[i])
            continue;
        //复制到n中，然后用3sum方法解决
        vector<int>n(num.begin() + i + 1, num.end());
        vector<vector<int>> ret = threeSum(n, target - num[i]);
        for (int j = 0; j < ret.size(); j++)
        {
            ret[j].insert(ret[j].begin(), num[i]);//在结果前插入num[i]
            result.push_back(ret[j]);
        }
    }
    return result;
}
vector<vector<int>> threeSum(vector<int>&num,int target)
{
    vector<vector<int>> result;//返回二维数组
    sort(num.begin(), num.end());//首先进行排序
    int n = num.size();
    for (int i = 0; i < n - 2; i++)// 因为三个数，所以第一个数最大只能为len-3
    {
        //去掉重复值,这里一定要注意，i如果与前一个i所在值相同，则
        //不必计算了，直接另i++
        //不能写成num[i]==num[i+1]
        if (i > 0 && num[i-1] == num[i])
            continue;
        int a = num[i];
        int low = i + 1;
        int high = n - 1;
        while (low < high)
        {
            int b = num[low];
            int c = num[high];
            if (a+b+c==target)//满足条件，将其加入数组中
            {
                vector<int>v;
                v.push_back(a);
                v.push_back(b);
                v.push_back(c);
                result.push_back(v);
                //继续寻找下一个满足条件的值，去重值
                while (low < high&&num[low] == num[low + 1]) low++;
                low++;
                while (high > low&&num[high] == num[high - 1]) high--;
                high--;
            }
            else if (a + b + c>target)
            {
                while (high > low&&num[high] == num[high - 1])
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
    return result;
}
//打印二维数组
void printMatrix(vector<vector<int>> &matrix)
{
    //基于范围for循环，等效于下面的for
    for (auto c : matrix)
    {
        cout << "[";
        for (auto r : c)
            cout << r << " ";
        cout <<"]"<< endl;
    }
    /*for (int i = 0; i < matrix.size(); i++)
    {
    cout << "[";
    for (int j = 0; j < matrix[i].size(); j++)
    cout << matrix[i][j] << "  ";
    cout << "]" << endl;
    }*/
}
int main()
{
    vector<int>num = { 1, 0, -1, 0, - 2, 2 };
    vector<vector<int>>result = fourSum(num,0);
    printMatrix(result);
    return 0;
}