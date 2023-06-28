class Solution{
public:
    void traversal(TreeNode *root, int level, vector<int> &ans){
        if(!root) return;
        if(ans.size() == level) ans.push_back(root->val);
        traversal(root->right, level + 1, ans);
        traversal(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode *root){
        vector<int> ans;
        traversal(root, 0, ans);
        return ans;
    }
};
