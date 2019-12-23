#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


void print_funcition(vector<int> nums) {
    for(auto & n: nums) {
        cout << n << " ";
    }
    cout << endl;
}

// 普通二分搜索的形式
int binary_search(vector<int> & nums, int target) {
    int len = nums.size();
    if(len < 1) return -1;
    int low = 0, high = len - 1;
    while(low <= high) {             // 一定要注意这里是<=符号
        int mid = (low + high) / 2;
        if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

// 寻找左侧边界的二分搜索
int low_bound(vector<int> &nums, int target) {
    int len = nums.size();
    if(len < 1) return -1;
    int low = 0, high = len;
    while(low < high) {
        int mid = (low + high) >> 1;
        if(nums[mid] == target) {
            high = mid;
        } else if(nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    if(low == len) return -1;
    return nums[low] == target ? low: -1;
}

// 寻找右侧边界
int right_bound(vector<int> &nums, int target) {
    int len = nums.size();
    if(len < 1) return -1;
    int low = 0, high = len;
    while(low < high) {
        int mid = (low + high) >> 1;
        if(nums[mid] == target) {
            low = mid + 1;
        } else if(nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    if(low == 0) return -1;
    return nums[low-1] == target ? (low-1) : -1;
}

int main() {
    vector<int> nums = {5,7,7,8,8,15};
    cout<< binary_search(nums, 1) << endl;
    cout<< low_bound(nums, 7) << endl;
    cout<< right_bound(nums,8) << endl;
    return 0;
}