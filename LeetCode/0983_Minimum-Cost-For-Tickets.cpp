class Solution{
    int dfs(int i, vector<int> &dp, vector<int> &days, vector<int> &costs){
        if(i >= days.size())
            return 0;

        if(dp[i] > -1)
            return dp[i];

        int nextW = i;
        while(nextW < days.size() && days[nextW] < days[i] + 7)
            ++nextW;
        int nextM = i;
        while(nextM < days.size() && days[nextM] < days[i] + 30)
            ++nextM;

        return dp[i] = min(costs[0] + dfs(i + 1, dp, days, costs),
                           min(costs[1] + dfs(nextW, dp, days, costs),
                               costs[2] + dfs(nextM, dp, days, costs)));
    }
public:
    int mincostTickets(vector<int> &days, vector<int> &costs){
        vector<int> dp(days.size() + 1, -1);

        return dfs(0, dp, days, costs);
    }
};
