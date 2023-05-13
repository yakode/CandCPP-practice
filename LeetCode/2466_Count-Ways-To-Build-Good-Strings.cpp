class Solution{
public:
    int dp[100000+5];
    const int mod = 1e9 + 7;

    int dfs(int len_remain, int zero, int one){
        if(len_remain < 0) return 0;

        if(len_remain == 0) return 1;

        if(dp[len_remain] > -1) return dp[len_remain];

        return dp[len_remain] = (dfs(len_remain-zero, zero, one) + dfs(len_remain-one, zero, one)) % mod;
    }

    int countGoodStrings(int low, int high, int zero, int one){
        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for(int i = high; i >= low; --i){
            ans += dfs(i, zero, one);
            ans %= mod;
        }

        return ans;
    }
};

// I think it is a better method
class Solution{
public:
    int dp[100000+5];
    const int mod = 1e9 + 7;

    int dfs(int len, int low, int high, int zero, int one){
        if(len > high) return 0;

        if(dp[len] > -1) return dp[len];

        if(len >= low) return dp[len] = (dfs(len+zero, low, high, zero, one) + dfs(len+one, low, high, zero, one) + 1) % mod;
        return dp[len] = (dfs(len+zero, low, high, zero, one) + dfs(len+one, low, high, zero, one)) % mod;
    }

    int countGoodStrings(int low, int high, int zero, int one){
        memset(dp, -1, sizeof(dp));

        return dfs(0, low, high, zero, one);
    }
};
