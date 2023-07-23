class Solution{
    void dfs(int j, vector<vector<int>> &matrix, int numSelect, vector<int> &row1, int &ans){
        if(numSelect == 0){
            int tmp = 0;
            for(int &n: row1)
                if(n == 0)
                    ++tmp;
            ans = max(ans, tmp);
        }
        if(j == matrix[0].size())
            return;
        
        dfs(j + 1, matrix, numSelect, row1, ans);
        for(int i = 0; i < matrix.size(); ++i){
            if(matrix[i][j] == 1)
                --row1[i];
        }
        dfs(j + 1, matrix, numSelect - 1, row1, ans);
        for(int i = 0; i < matrix.size(); ++i){
            if(matrix[i][j] == 1)
                ++row1[i];
        }
    }

public:
    int maximumRows(vector<vector<int>> &matrix, int numSelect){
        int ans = 0;
        vector<int> row1(matrix.size(), 0);
        
        for(int i = 0; i < matrix.size(); ++i)
            for(int j = 0; j < matrix[i].size(); ++j)
                if(matrix[i][j] == 1)
                    ++row1[i];

        dfs(0, matrix, numSelect, row1, ans);

        return ans;
    }
};
