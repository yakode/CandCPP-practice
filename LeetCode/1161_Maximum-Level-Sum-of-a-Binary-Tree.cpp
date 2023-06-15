class Solution{
public:
    int arr[10000] = {0};
    int maxLevel;

    void dfs(TreeNode *node, int level){
        if(node == nullptr) return;

        maxLevel = max(maxLevel, level);

        arr[level] += node->val;

        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }

    int maxLevelSum(TreeNode *root){
        maxLevel = 0;
        dfs(root, 0);

        int ans = 0;
        for(int i = 0; i <= maxLevel; ++i){
            if(arr[i] > arr[ans]) ans = i;
        }

        return ans + 1;
    }
};
