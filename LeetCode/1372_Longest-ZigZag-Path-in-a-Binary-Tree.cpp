/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 1;

    int dfs(TreeNode* root, bool dir){
        int zl = 1;
        int zr = 1;

        if(root->left != nullptr){
            zl += dfs(root->left, false);
            if(zl > ans) ans = zl;
        }
        if(root->right != nullptr){
            zr += dfs(root->right, true);
            if(zr > ans) ans = zr;
        }

        if(!dir) return zr;
        return zl;
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, false);
        dfs(root, true);
        
	return ans-1;
    }
};
