class Solution{
public:
    void dfs(int i, vector<int> &jobs, int k, vector<int> &workers, int &ans){
        if(i == jobs.size()){
            int tmp = 0;
            for(int j = 0; j < k; ++j) tmp = max(tmp, workers[j]);
            ans = min(ans, *max_element(workers.begin(), workers.end()));
            return;
        }

        for(int j = 0; j < k; ++j){
            if(workers[j] + jobs[i] >= ans) continue;
            
            workers[j] += jobs[i];
            dfs(i + 1, jobs, k, workers, ans);
            workers[j] -= jobs[i];

            if(workers[j] == 0) break;
        }
    }
    
    int minimumTimeRequired(vector<int> &jobs, int k){
        int ans = INT_MAX;
        vector<int> workers(k, 0);

        sort(jobs.begin(), jobs.end(), greater<int>());
        dfs(0, jobs, k, workers, ans);

        return ans;
    }
};
