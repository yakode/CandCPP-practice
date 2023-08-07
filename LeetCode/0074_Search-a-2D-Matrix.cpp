class Solution{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target){
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m, middle;

        while(left < right){
            middle = left + (right - left) / 2;
            if(matrix[middle][n - 1] < target){
                left = middle + 1;
            }else if(matrix[middle][n - 1] > target){
                right = middle;
            }else{
                return true;
            }
        }
        if(left >= m)
            return false;

        m = left;
        left = 0;
        right = n;
        while(left < right){
            middle = left + (right - left) / 2;
            if(matrix[m][middle] > target)
                right = middle;
            else if(matrix[m][middle] < target)
                left = middle + 1;
            else
                return true;
        }

        return false;
    }
};
