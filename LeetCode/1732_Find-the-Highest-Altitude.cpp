class Solution{
public:
    int largestAltitude(vector<int> &gain){
        int ans = 0;
        int altitude = 0;
        
        for(int i = 0; i < gain.size(); ++i){
            altitude += gain[i];
            ans = max(ans, altitude);
        }

        return ans;
    }
};
