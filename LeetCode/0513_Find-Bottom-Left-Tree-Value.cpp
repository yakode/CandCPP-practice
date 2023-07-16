class Solution{
    void traversal(TreeNode *root, int level, int &last_level, int &ans){
        if(!root)
            return;

        traversal(root->left, level + 1, last_level, ans);
        if(level > last_level){
            ans = root->val;
            last_level = level;
        }
        traversal(root->right, level + 1, last_level, ans);
    }
public:
    int findBottomLeftValue(TreeNode *root){
        int ans = root->val;
        int last_level = 0;

        traversal(root, 0, last_level, ans);

        return ans;
    }
};
