// Author : yqtao
// Date   : 2016-7-6
// Email  : yqtao@whu.edu.cn
/**********************************************************************************
*
* Given two sorted integer arrays A and B, merge B into A as one sorted array.
*
* Note:
*   You may assume that A has enough space (size that is greater or equal to m + n)
*   to hold additional elements from B. The number of elements initialized in A and B
*   are m and n respectively.
*
**********************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
//Solutins 1:   4ms
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = 0, j = 0, k = 0;
	vector<int>temp(nums1.begin(), nums1.end());  //using a vector to restore nums1,
	while (i<m&&j<n)
	{
		if (temp[i] <= nums2[j])
			nums1[k++] = temp[i++];
		else
			nums1[k++] = nums2[j++];
	}
	while (i<m)
		nums1[k++] = temp[i++];
	while (j<n)
		nums1[k++] = nums2[j++];
}
//Solution 2: 4ms,but i think this way is better then above
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = m - 1, j = n - 1, tar = m + n - 1;    //from end to head
	while (j >= 0) {
		nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
	}
}
