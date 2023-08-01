class Solution{
    void dfs(int i, vector<int> &nums, vector<int> &path, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(path);
        }

        for(int j = 0; j < nums.size(); ++j){
            if(nums[j] == -11)
                continue;

            path[i] = nums[j];
            nums[j] = -11;
            dfs(i + 1, nums, path, ans);
            nums[j] = path[i];
        }
    }
    
public:
    vector<vector<int>> permute(vector<int> &nums){
        vector<vector<int>> ans;
        vector<int> path(nums.size());

        dfs(0, nums, path, ans);

        return ans;
    }
};
