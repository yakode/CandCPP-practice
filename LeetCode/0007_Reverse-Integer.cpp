class Solution {
public:
    int reverse(int x) {
        int digit[15] = {0};
        long long int tmp = x;
        if(tmp < 0) tmp *= -1;

        int i;
        for(i = 0; tmp; ++i){
            digit[i] = tmp % 10;
            tmp /= 10;
        }

        long long int ans = 0, base = 1;
        for(; i; --i){
            ans += digit[i-1] * base;
            base *= 10;
        }

        if(ans > 2147483647 || ans < -2147483648) return 0;
        if(x < 0) return ans * -1;
        return ans;
    }
};
