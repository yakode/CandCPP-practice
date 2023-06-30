class Solution{
public:
    void traversal(TreeNode *root, vector<int> &ans, int &cur, int &cnt, int &maxi){
        if(!root) return;

        traversal(root->left, ans, cur, cnt, maxi);
        if(root->val != cur){
            if(cnt > maxi){
                ans.clear();
                ans.push_back(cur);
                maxi = cnt;
            }else if(cnt == maxi){
                ans.push_back(cur);
            }
            cur = root->val;
            cnt = 1;
        }else{
            cnt++;
        }
        traversal(root->right, ans, cur, cnt, maxi);
    }
    vector<int> findMode(TreeNode *root){
        int cur = root->val, cnt = 0, maxi = 0;
        vector<int> ans;

        traversal(root, ans, cur, cnt, maxi);
        if(cnt > maxi){
            ans.clear();
            ans.push_back(cur);
        }else if(cnt == maxi){
            ans.push_back(cur);
        }

        return ans;
    }
};
