class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
        TreeNode *ans = root;

        while(ans){
            if(ans->val < p->val && ans->val < q->val){
                ans = ans->right;
            }else if(ans->val > p->val && ans->val > q->val){
                ans = ans->left;
            }else{
                return ans;
            }
        }

        return nullptr;
    }
};
