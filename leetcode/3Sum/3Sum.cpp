// Author : yqtao
// Date   : 2016.7.30
// Email  : yqtao@whu.edu.cn
/**************************************************************************************
*Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
* Find all unique triplets in the array which gives the sum of zero.
* 
* Note:
* 
* Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
* The solution set must not contain duplicate triplets.
* 
*     For example, given array S = {-1 0 1 2 -1 -4},
* 
*     A solution set is:
*     (-1, 0, 1)
*     (-1, -1, 2)
**********************************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>&nums)
{
    vector<vector<int>> result;//返回二维数组
    sort(nums.begin(), nums.end());//首先进行排序
    int n = nums.size();
    for (int i = 0; i < n - 2; i++)// 因为三个数，所以第一个数最大只能为len-3
    {
        //去掉重复值,这里一定要注意，i如果与前一个i所在值相同，则
        //不必计算了，直接另i++
        //不能写成nums[i]==nums[i+1]
        if (i > 0 && nums[i-1] == nums[i])
            continue;
        int a = nums[i];
        int low = i + 1;
        int high = n - 1;
        while (low < high)
        {
            int b = nums[low];
            int c = nums[high];
            if (a+b+c==0)//满足条件，将其加入数组中
            {
                vector<int>v;
                v.push_back(a);
                v.push_back(b);
                v.push_back(c);
                result.push_back(v);
                //继续寻找下一个满足条件的值，去重值
                while (low < high&&nums[low] == nums[low + 1]) low++;
                low++;
                while (high > low&&nums[high] == nums[high - 1]) high--;
                high--;
            }
            else if (a + b + c>0)
            {
                while (high > low&&nums[high] == nums[high - 1])
                    high--;
                high--;
            }
            else
            {
                while (low < high&&nums[low] == nums[low + 1]) 
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
    vector<int>nums = { -1, 0, 1, 2, - 1, - 4 };
    //vector<int >nums= {-1, 1, 1, 1, -1, -1, 0, 0, 0};
    vector<vector<int>>result = threeSum(nums);
    printMatrix(result);
    return 0;
}
