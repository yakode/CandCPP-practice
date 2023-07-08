class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode *root){
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int level = 0;

        if(root)
            q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; ++i){
                TreeNode *ptr = q.front();
                q.pop();
                if(ptr->left)
                    q.push(ptr->left);
                if(ptr->right)
                    q.push(ptr->right);
                if(ans.size() <= level) ans.push_back(vector<int>());
                ans[level].push_back(ptr->val);
            }
            ++level;
        }

        return ans;
    }
};
