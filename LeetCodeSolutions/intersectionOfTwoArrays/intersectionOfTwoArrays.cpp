// Date   : 2016.08.24
// Author : yqtao
// https://github.com/yqtaowhu

```
/***************************************************************************************
*
* Given two arrays, write a function to compute their intersection.
*
* Example:
* Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
*
* Note:
* Each element in the result must be unique.
* The result can be in any order.
*
***************************************************************************************/
//用set
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> intersection(vector<int> &num1, vector<int> &num2)
{
	set<int>s1, s2;
	vector<int>result;
	auto iter = num1.begin();
	for (; iter != num1.end(); ++iter)
		s1.insert(num1[*iter]);
	auto iter2 = num2.begin();
	for (; iter2 != num2.end(); ++iter2)
		if (s1.find(*iter2) != s1.end())//说明在s1中找到了相同的数
			s2.insert(*iter2);//插入s2中
	auto iter3 = s2.begin();//s2中全是查找相同的元素，且没有重复的值
	for (; iter3 != s2.end(); ++iter3)
		result.push_back(*iter3);
         
	return result;
}
```
//用哈希表

```
class Solution {
    public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int> m;
       vector<int> res;
       for (int i=0;i<nums1.size();i++)
           m[nums1[i]]=1;
       for (int i=0;i<nums2.size();i++) {
           if (m[nums2[i]]>0) {
               res.push_back(nums2[i]);
               m[nums2[i]]=0;
           }
       }
       return res;
    }
};
```