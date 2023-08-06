class Solution{
    int dp[50] = {0};

public:
    int numTrees(int n){
        int ans = 0, left, right;

        if(n == 0)
            return 1;

        if(dp[n] > 0)
            return dp[n];

        for(int i = 0; i < n; ++i){
            left = numTrees(i);
            right = numTrees(n - i - 1);
            ans += left * right;
        }

        return dp[n] = ans;
    }
};
