class Solution{
    void dfs(int i, vector<int> &nums, vector<int> item, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(item);
            return;
        }

        dfs(i + 1, nums, item, ans);
        item.push_back(nums[i]);
        dfs(i + 1, nums, item, ans);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums){
        vector<vector<int>> ans;

        dfs(0, nums, vector<int>(), ans);

        return ans;
    }
};
