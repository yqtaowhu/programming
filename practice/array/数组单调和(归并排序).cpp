
/***************************************************************
现定义数组单调和为所有元素i的f(i)值之和。
这里的f(i)函数定义为元素i左边(不包括其自身)小于等于它的数字之和。请设计一个高效算法，计算数组的单调和。
给定一个数组A同时给定数组的大小n，请返回数组的单调和。
保证数组大小小于等于500，同时保证单调和不会超过int范围。
测试样例：
[1,3,5,2,4,6],6
返回：27
******************************************************************/
class MonoSum {
public:
    int ret = 0;
    void merge_sort(vector<int>&arr,int low,int high) {
        if (low<high) {
        	int mid = (low+high)/2;
       	 	merge_sort(arr,low,mid);
        	merge_sort(arr,mid+1,high);
        	merge(arr,low,mid,high);
    	}
    }
    void merge(vector<int>&arr,int low,int mid,int high) {
        int i=low,j=mid+1,k=0;
        vector<int> tmp(high-low+1);
        while(i<=mid&&j<=high) {
            if (arr[i]>arr[j]) tmp[k++]=arr[j++];
            else {
                ret+=arr[i]*(high-j+1);
                tmp[k++]=arr[i++];
            }
		}
        while(i<=mid) tmp[k++]=arr[i++];
        while(j<=high) tmp[k++]=arr[j++];
        for (int i=0;i<k;i++) arr[low+i]=tmp[i];
    }
    int calcMonoSum(vector<int> A, int n) {
       if (n<=1) return 0;
       merge_sort(A,0,n-1);
       return ret;
    }
};