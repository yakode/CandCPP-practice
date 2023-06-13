class Solution{
public:
    int equalPairs(vector<vector<int>> &grid){
        int ans = 0;
        

        for(int i = 0; i < grid.size(); ++i){
            // row i
            for(int j = 0; j < grid.size(); ++j){
                // col j
                int tmp = 1;
                for(int k = 0; k < grid.size(); ++k){
                    if(grid[i][k] != grid[k][j]){
                        tmp = 0;
                        break;
                    }
                }
                ans += tmp;
            }
        }

        return ans;
    }
};
