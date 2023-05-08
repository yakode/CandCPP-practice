class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        
        for(int i  = 0, j = mat[0].size()-1; i < mat[0].size(); ++i, --j){
            ans += mat[i][i];
            ans += mat[i][j];
        }
        if(mat[0].size() % 2 == 1) ans -= mat[mat[0].size() / 2][mat[0].size() / 2];

        return ans;
    }
};
