class Solution{
    double dp[200][200] = {0};

    double dfs(int a, int b){
        if(a <= 0 && b <= 0)
            return 0.5;
        if(a <= 0)
            return 1;
        if(b <= 0)
            return 0;

        if(dp[a][b] > 0)
            return dp[a][b];

        double ret = 0;
        ret += 0.25 * dfs(a - 4, b);
        ret += 0.25 * dfs(a - 3, b - 1);
        ret += 0.25 * dfs(a - 2, b - 2);
        ret += 0.25 * dfs(a - 1, b - 3);
        
        return dp[a][b] = ret;
    }
    
public:
    double soupServings(int n){
        if(n > 4800)
            return 1;
        return dfs(ceil(n / 25.0), ceil(n / 25.0));
    }
};
