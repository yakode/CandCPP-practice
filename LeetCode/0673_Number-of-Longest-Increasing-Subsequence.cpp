class Solution{
public:
    int findNumberOfLIS(vector<int> &nums){
        vector<int> cnt(nums.size() + 1, 1);
        vector<int> len(nums.size() + 1, 1);
        int max_len = 0, ans = 0;

        for(int i = 0; i < nums.size(); ++i){
            for(int j = i - 1; j >= 0; --j){
                if(nums[i] <= nums[j])
                    continue;
                if(len[i] == len[j] + 1){
                    cnt[i] += cnt[j];
                }else if(len[i] < len[j] + 1){
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                }
            }

            if(max_len == len[i]){
                ans += cnt[i];
            }else if(max_len < len[i]){
                max_len = len[i];
                ans = cnt[i];
            }
        }

        return ans;
    }
};
