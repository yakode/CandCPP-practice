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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;

        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root, 0});
        
	while(!q.empty()){
            pair<TreeNode*, unsigned int> l = q.front(), r = q.back();
            
	    if(r.second-l.second+1 > ans) ans = r.second - l.second + 1 ;

            int Q = q.size();
            while(Q--){
                if(q.front().first->left != nullptr){
                    q.push({q.front().first->left, q.front().second*2});
                }
                if(q.front().first->right != nullptr){
                    q.push({q.front().first->right, q.front().second*2+1});
                }
                q.pop();
            }    
        }

        return ans;
    }
};
