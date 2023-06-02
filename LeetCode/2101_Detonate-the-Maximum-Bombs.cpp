class Solution{
public:
    #define dis(a, b) ((long long)(a[0] - b[0]) * (a[0] - b[0]) + (long long)(a[1] - b[1]) * (a[1] - b[1]))

    int dfs(int i, vector<vector<int>> &detonate, bool isDetonate[100]){
        if(isDetonate[i]) return 0;
        isDetonate[i] = true;

        int ret = 1;
        for(int j = 0; j < detonate[i].size(); ++j){
            ret += dfs(detonate[i][j], detonate, isDetonate);
        }

        return ret;
    }

    int maximumDetonation(vector<vector<int>> &bombs){
        vector<vector<int>> detonate(bombs.size());

        for(int i = 0; i < bombs.size(); ++i){
            long long int r2 = (long long)bombs[i][2] * bombs[i][2];
            for(int j = 0; j < bombs.size(); ++j){
                if(i == j) continue;

                long long int d = dis(bombs[i], bombs[j]);
                if(d <= r2){
                    detonate[i].push_back(j);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < bombs.size(); ++i){
            bool check[100] = {0};
            ans = max(ans, dfs(i, detonate, check));
        }

        return ans;
    }
};
