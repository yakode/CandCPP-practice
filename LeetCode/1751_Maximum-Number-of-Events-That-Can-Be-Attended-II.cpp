class Solution{
    int dfs(int i, vector<vector<int>> &events, vector<vector<int>> &dp, int nr){
        if(i >= events.size() || nr == 0)
            return 0;

        if(dp[i][nr] != 0)
            return dp[i][nr];

        int left = i + 1, right = events.size(), middle = events.size();
        while(left < right){
            middle = left + (right - left) / 2;
            if(events[middle][0] > events[i][1] && events[middle - 1][0] < events[i][1]){
                left = middle;
                break;
            }
            if(events[middle][0] > events[i][1])
                right = middle;
            else
                left = middle + 1;
        }

        return dp[i][nr] = max(dfs(i + 1, events, dp, nr), dfs(left, events, dp, nr - 1) + events[i][2]);
    }
    
public:
    int maxValue(vector<vector<int>> &events, int k){
        sort(events.begin(), events.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });

        vector<vector<int>> dp(events.size() + 1, vector<int>(k + 1, 0));

        return dfs(0, events, dp, k);
    }
};
