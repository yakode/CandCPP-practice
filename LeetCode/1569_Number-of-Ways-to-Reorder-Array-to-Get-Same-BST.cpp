class Solution{
public:
    vector<vector<int>> combination;
    int mod = 1e9 + 7;

    int dfs(vector<int> &nums){
        if(nums.size() <= 2) return 1;

        int root = nums[0];
        vector<int> left, right;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long ans = combination[left.size() + right.size()][left.size()];
        ans = (ans * dfs(left)) % mod;
        ans = (ans * dfs(right)) % mod;
        return ans;
    }

    int numOfWays(vector<int> &nums){
        for(int i = 0; i <= nums.size(); ++i){
            combination.push_back(vector<int>(i + 1, 1));
        }
        for(int i = 2; i <= nums.size(); ++i){
            for(int j = 1; j < i; ++j){
                combination[i][j] = (combination[i - 1][j - 1] + combination[i - 1][j]) % mod;
            }
        }
        
        return dfs(nums) - 1;
    }
};
