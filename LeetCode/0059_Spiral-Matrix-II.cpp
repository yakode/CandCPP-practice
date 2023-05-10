class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));

        int N = n * n;
        int x = 0, y = 0; // row x, col y
        
        for(int i = 0, cnt = 0; cnt < N; ++i){
            for(; cnt < N && y < n - i; ++y) ans[x][y] = ++cnt;
            y--;
            x++;
            for(; cnt < N && x < n - i; ++x) ans[x][y] = ++cnt;
            x--;
            y--;
            for(; cnt < N && y >= i; --y) ans[x][y] = ++cnt;
            y++;
            x--;
            for(; cnt < N && x > i; --x) ans[x][y] = ++cnt;
            x++;
            y++;     
        }

        return ans;
    }
};
