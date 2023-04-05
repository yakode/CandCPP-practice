class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unsigned int len = nums.size();
        for(int i = 0; i < len; ++i){
            for(int j = 0; j < len; ++j){
                if(i ==j) continue;
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};
