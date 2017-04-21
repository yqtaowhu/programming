// Date   : 2016.08.26
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Implement int sqrt(int x).
* 
* Compute and return the square root of x.
*               
**********************************************************************************/
//binary search
class Solution {
public:
    int mySqrt(int x) {
        if (0 == x) return 0;
        int left = 1, right = x, ans;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

// http://en.wikipedia.org/wiki/Newton%27s_method
int sqrt_nt(int x) {
    if (x == 0) return 0;
    double last = 0;
    double res = 1;
    while (res != last)
    {
        last = res;
        res = (res + x / res) / 2;
    }
    return int(res);
}
