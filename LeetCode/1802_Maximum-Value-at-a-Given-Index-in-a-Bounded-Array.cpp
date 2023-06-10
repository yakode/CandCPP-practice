class Solution{
public:
    int maxValue(int n, int index, int maxSum){
        // nums[0] nums[1] ... nums[index] nums[index + 1] ...
        // |------nleft------|------1-----|------nright------|
        int nleft = index, nright = n - index - 1;
        int left = 1, right = maxSum + 1 , mid;
        long long cnt;

        while(left < right){
            mid = left + (right - left) / 2;
            
            cnt = mid;
            if(mid > nleft) cnt += (long long)((mid - 1) + (mid - nleft)) * nleft / 2;
            else cnt += ((long long)mid * (mid - 1)) / 2 + (nleft - mid + 1);
            if(mid > nright) cnt += (long long)((mid - 1) + (mid - nright)) * nright / 2;
            else cnt += ((long long)mid * (mid - 1)) / 2 + (nright - mid + 1);

            if(cnt > maxSum){
                right = mid;
            }else if(cnt < maxSum){
                left = mid + 1;
            }else{
                return mid;
            }
        }

        return left - 1;
    }
};
