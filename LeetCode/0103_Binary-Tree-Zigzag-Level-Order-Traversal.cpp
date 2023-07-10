class Solution{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root){
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int level = 0;

        if(root)
            q.push(root);

        while(!q.empty()){
            int n = q.size();

            ans.push_back(vector<int>());

            for(int i = 0; i < n; ++i){
                TreeNode *ptr = q.front();
                q.pop();

                if(level % 2 == 0)
                    ans[level].push_back(ptr->val);
                else
                    ans[level].insert(ans[level].begin(), ptr->val);

                if(ptr->left)
                    q.push(ptr->left);
                if(ptr->right)
                    q.push(ptr->right);
            }
            
            ++level;
        }

        return ans;
    }
};
