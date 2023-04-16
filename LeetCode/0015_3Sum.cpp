class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < N; ++i){
            for(int j = i+1; j < N; ++j){
                if(ans.size() !=0 && ans[ans.size()-1][0] == nums[i] && ans[ans.size()-1][1] >= nums[j])
                    continue;
                // binary search (nums[i]+nums[j]) * -1
                int l = j+1, r = N, m;
                int target = -1 * (nums[i]+nums[j]);
                if(target > 100000 || target < -100000) continue;
                while(l < r){
                    m = (l+r) / 2;
                    if(nums[m] < target) l = m+1;
                    else if(nums[m] > target) r = m;
                    else{
                        ans.push_back({nums[i], nums[j], nums[m]});
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
