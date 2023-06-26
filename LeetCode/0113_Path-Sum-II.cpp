class Solution{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum){
        if(!root) return vector<vector<int>>();

        targetSum -= root->val;
        if(targetSum == 0 && !root->left && !root->right) return vector<vector<int>> (1, vector<int>(1, root->val));

        vector<vector<int>> lvec = pathSum(root->left, targetSum);
        vector<vector<int>> rvec = pathSum(root->right, targetSum);
        lvec.insert(lvec.end(), rvec.begin(), rvec.end());
        for(auto &v: lvec){
            v.insert(v.begin(), root->val);
        }
        return lvec;
    }
};
