class Solution{
public:
    void dfs(TreeNode *root, string path, vector<string> &ans){
        if(path.size() > 0) path += "->";
        path += to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(path);
            return;
        }

        if(root->left) dfs(root->left, path, ans);
        if(root->right) dfs(root->right, path, ans);
    }
    
    vector<string> binaryTreePaths(TreeNode *root){
        vector<string> ans;
        dfs(root, "", ans);
        return ans;
    }
};
