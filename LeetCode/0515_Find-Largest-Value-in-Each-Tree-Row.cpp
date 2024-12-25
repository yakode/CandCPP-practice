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
class Solution{
public:
    vector<int> largestValues(TreeNode *root){
        vector<int> ans;
        queue<TreeNode*> q;
        
        if(root)
            q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int maxi = INT_MIN;
            for(int i = 0; i < sz; ++i){
                if(q.front()->val > maxi)
                    maxi = q.front()->val;
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            ans.push_back(maxi);
        }

        return ans;
    }
};
