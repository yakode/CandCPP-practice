class Solution{
public:
    vector<int> productExceptSelf(vector<int> &nums){
        vector<int> ans(nums.size(), 0);
        int productAll = 1;
        int zero = -1;

        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0){
                if(zero >= 0){
                    return ans;
                }
                zero = i;
                continue;
            }
            productAll *= nums[i];
        }

        if(zero >= 0){
            ans[zero] = productAll;
            return ans;
        }

        for(int i = 0; i < nums.size(); ++i){
            ans[i] = productAll / nums[i];
        }

        return ans;
    }
};
