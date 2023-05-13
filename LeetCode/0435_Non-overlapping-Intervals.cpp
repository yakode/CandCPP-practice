class Solution{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        int ans = 0;

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });

        int low = -5e4 - 1;
        for(int i = 0; i < intervals.size(); ++i){
            if(intervals[i][0] < low){
                // overlapping
                ans++;
            }else{
                low = intervals[i][1];
            }
        }

        return ans;
    }
};
