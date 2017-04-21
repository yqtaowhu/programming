Valid Perfect Square
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

//binary
class Solution {
public:
    bool isPerfectSquare(int num) {
    long long l = 0, r = num;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        long long sqmid = mid * mid;
        if (sqmid > num) r = mid - 1;
        else if (sqmid < num) l = mid + 1;
        else return true;
    }
    return false;
}
};