class Solution {
public:
    void dfs(int i, int taken, vector<int> &skills, unordered_map<int, vector<int>> &dp){
        if(i == skills.size())
            return;
        
        int tmp = taken | skills[i];
        if(skills[i] != 0 && (dp.count(tmp) == 0 || dp[tmp].size() > dp[taken].size() + 1)){
            dp[tmp] = dp[taken];
            dp[tmp].push_back(i);
            dfs(i + 1, tmp, skills, dp);
        }
        dfs(i + 1, taken, skills, dp);
    }

    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people) {
        vector<int> skills(people.size(), 0);
        unordered_map<int, vector<int>> dp;

        sort(req_skills.begin(), req_skills.end());

        for(int i = 0; i < people.size(); ++i){
            int k = 0;
            sort(people[i].begin(), people[i].end());
            for(int j = 0; j < people[i].size(); ++j){
                while(req_skills[k] != people[i][j])
                    ++k;
                int tmp = 1 << k;
                skills[i] |= tmp;
            }
        }

        dfs(0, 0, skills, dp);

        return dp[pow(2, req_skills.size())- 1];
    }
};
