class Solution {
public:
    int arrangeCoins(int n) {
        long left = 1, right = (long)n+1;
        long mid, mid2;

        while(left < right){
            mid = left + (right - left) / 2;
            mid2 = (mid * mid + mid) / 2;

            if(mid2 < n) left = mid + 1;
            else if(mid2 > n) right = mid;
            else return mid;
        }

        return left-1;
    }
};
