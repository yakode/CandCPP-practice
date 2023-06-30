// Ugly code :(
class Solution{
public:
    vector<TreeNode*> dfs(TreeNode *root, vector<int>& to_delete){
        if(!root) return vector<TreeNode*>();

        vector<TreeNode*> ans;
        vector<TreeNode*> left = dfs(root->left, to_delete);
        vector<TreeNode*> right = dfs(root->right, to_delete);
        bool del_l = false, del_r = false;
        if(root->left){
            for(auto &i: to_delete){
                if(root->left->val == i){
                    root->left = nullptr;
                    del_l = true;
                    break;
                }
            }
        }
        if(root->right){
            for(auto &i: to_delete){
                if(root->right->val == i){
                    root->right = nullptr;
                    del_r = true;
                    break;
                }
            }
        }
        for(auto &i: to_delete){
            if(root->val == i){
                if(!del_l && root->left) ans.push_back(root->left);
                if(!del_r && root->right) ans.push_back(root->right);
                break;
            }
        }
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }

    vector<TreeNode*> delNodes(TreeNode *root, vector<int>& to_delete){
        if(!root) return vector<TreeNode*>();

        vector<TreeNode*> ans;
        vector<TreeNode*> left = dfs(root->left, to_delete);
        vector<TreeNode*> right = dfs(root->right, to_delete);
        bool del_l = false, del_r = false;
        if(root->left){
            for(auto &i: to_delete){
                if(root->left->val == i){
                    root->left = nullptr;
                    del_l = true;
                    break;
                }
            }
        }
        if(root->right){
            for(auto &i: to_delete){
                if(root->right->val == i){
                    root->right = nullptr;
                    del_r = true;
                    break;
                }
            }
        }
        bool del = false;
        for(auto &i: to_delete){
            if(root->val == i){
                if(!del_l && root->left) ans.push_back(root->left);
                if(!del_r && root->right) ans.push_back(root->right);
                del = true;
                break;
            }
        }
        if(!del) ans.push_back(root);
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
};
