class Solution{
public:
    int trap(vector<int> &height){
        int ans = 0;
        vector<int> left(height.size());
        vector<int> right(height.size());

        int maxi = 0;
        for(int i = 0; i < height.size(); ++i){
            left[i] = maxi;
            maxi = max(maxi, height[i]);
        }
        maxi = 0;
        for(int i = height.size() - 1; i >= 0; --i){
            right[i] = maxi;
            maxi = max(maxi, height[i]);
        }

        for(int i = 0; i < height.size(); ++i){
            ans += max(0, (min(left[i], right[i]) - height[i]));
        }

        return ans;
    }
};
