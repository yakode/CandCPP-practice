class Solution{
public:
    #define slope(a, b) (((double)a[1] - b[1]) / ((double)a[0] - b[0]))

    bool checkStraightLine(vector<vector<int>> &coordinates){
        // vertical line
        if(coordinates[0][0] == coordinates[1][0]){
            for(int i = 2; i < coordinates.size(); ++i){
                if(coordinates[0][0] != coordinates[i][0])
                    return false;
            }
            return true;
        }

        double m = slope(coordinates[0], coordinates[1]);

        for(int i = 2; i < coordinates.size(); ++i){
            if(m != slope(coordinates[i - 1], coordinates[i]))
                return false;
        }

        return true;
    }
};
