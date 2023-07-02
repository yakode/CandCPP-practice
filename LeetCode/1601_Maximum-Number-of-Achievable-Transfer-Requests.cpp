class Solution{
public:
    void dfs(int i, vector<vector<int>> &requests, vector<int> &change, int cnt, int &ans){
        if(i == requests.size()){
            for(int j = 0; j < change.size(); ++j){
                if(change[j] != 0) return;
            }
            ans = max(ans, cnt);
            return;
        }

        dfs(i + 1, requests, change, cnt, ans);
        change[requests[i][0]]--;
        change[requests[i][1]]++;
        dfs(i + 1, requests, change, cnt + 1, ans);
        change[requests[i][0]]++;
        change[requests[i][1]]--;
    }

    int maximumRequests(int n, vector<vector<int>> &requests){
        vector<int> change(n, 0);
        int ans = 0;

        dfs(0, requests, change, 0, ans);
        
        return ans;
    }
};
