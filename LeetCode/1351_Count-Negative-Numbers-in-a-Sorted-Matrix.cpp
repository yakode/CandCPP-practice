class Solution{
public:
    int countNegatives(vector<vector<int>> &grid){
        //  4  3  2 -1
        //  3  2  1 -1
        //  1  1 -1 -2
        // -1 -1 -2 -3
        int ans = 0;
        int i = 0, j = grid[0].size() - 1;
        
        while(i < grid.size() && j >= 0){
            while(i < grid.size() && grid[i][j] >= 0) i++;
            ans += grid.size() - i;
            j--;
        }

        return ans;
    }
};
