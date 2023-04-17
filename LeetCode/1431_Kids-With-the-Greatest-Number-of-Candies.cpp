class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size(), false);
        int max_candy = *max_element(candies.begin(), candies.end());
        int threshold = max_candy - extraCandies;

        for(int i = 0; i < candies.size(); ++i){
            if(candies[i] >= threshold) ans[i] = true;
        }

        return ans;
    }
};
