// Date   : 2016.09.06
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a sorted array of integers, find the starting and ending position of a given target value.
* 
* Your algorithm's runtime complexity must be in the order of O(log n).
* 
* If the target is not found in the array, return [-1, -1].
* 
* For example,
* Given [5, 7, 7, 8, 8, 10] and target value 8,
* return [3, 4].
* 
*               
**********************************************************************************/
class Solution {
public:
    int binary_search(vector<int>& nums, int low, int high, int key){
        while (low<=high) {
            int mid = low + (high-low)/2;
            if (nums[mid] == key) return mid;
            else if (key > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos = binary_search(nums, 0, nums.size()-1, target);
        vector<int> v;
        int low = -1, high = -1;
        if (pos >=0){
            low = high = pos;
            int l = low;
            do {
                low = l;
                l = binary_search(nums, 0, low - 1, target);
            }while (l>=0);
    
            int h = high;
            do {
                high = h;
                h = binary_search(nums, high + 1, nums.size()-1, target);
            }while (h>=0);
        }
        v.push_back(low);
        v.push_back(high);
        return v;
    }
};

void printVector( vector<int>&  pt)
{
    cout << "{ ";
    for(int j=0; j<pt.size(); j++){
        cout << pt[j] << " ";
    }
    cout << "} " << endl;
}


int main()
{
    const int cnt=6;
    int a[cnt] ={5, 7, 7, 8, 8, 10};

    vector<int> v;
    v = searchRange(a, cnt, 8);     
    printVector(v);    


    int b[cnt] ={5, 5, 5, 8, 8, 10};
    v = searchRange(b, cnt, 5);     
    printVector(v);    

    int c[cnt] ={5, 5, 5, 5, 5, 5};
    v = searchRange(c, cnt, 5);     
    printVector(v);    
    return 0;
}
