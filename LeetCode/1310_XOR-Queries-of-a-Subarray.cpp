class Solution{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries){
        vector<int> ans(queries.size());
        vector<int> pre(arr.size() + 1, 0);

        pre[0] = 0;
        for(int i = 0; i < arr.size(); ++i){
            pre[i + 1] = pre[i] ^ arr[i];
        }

        for(int i = 0; i < queries.size(); ++i){
            ans[i] = pre[queries[i][0]] ^ pre[queries[i][1] + 1];
        }

        return ans;
    }
};
