class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size(); // how many row
        const int n = matrix[0].size(); // how many column
        const int cnt = m * n;

        vector<int> ans(m * n);

        int x = 0, y = 0;
        for(int i = 0, j = 0; j < cnt; ++i){
            for(; j < cnt && x < n-i; ++x) ans[j++] = matrix[y][x];
            x--;
            y++;
            for(; j < cnt && y < m-i; ++y) ans[j++] = matrix[y][x];
            y--;
            x--;
            for(; j < cnt && x >= i; --x) ans[j++] = matrix[y][x];
            x++;
            y--;
            for(; j < cnt && y > i; --y) ans[j++] = matrix[y][x];
            y++;
            x++;
        }

        return ans;
    }
};
