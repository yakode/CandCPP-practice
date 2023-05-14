class Solution{
public:
    int gcd(int x, int y){
        while(x != 0 && y != 0){
            if(x > y) x -= y;
            else y -= x;
        }

        return x + y;
    }

    int dp[1000000] = {0};
    int dfs(vector<int>& nums, int i, int state){
        if(i == nums.size()/2 + 1) return 0;

        if(dp[state] > 0) return dp[state];

        int ans = 0;
        for(int x = 0; x < nums.size(); ++x){
            for(int y = x + 1; y < nums.size(); ++y){
                int addxy = 1 << x | 1 << y;
                if((state & addxy) == 0){
                    ans = max(dfs(nums, i + 1, state | addxy) + i * gcd(nums[x], nums[y]), ans);
                }
            }
        }
        
        return dp[state] = ans;
    }

    int maxScore(vector<int>& nums){
        return dfs(nums, 1, 0);
    }
};
