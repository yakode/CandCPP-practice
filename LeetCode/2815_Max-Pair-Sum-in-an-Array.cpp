class Solution{
    bool check(int a, int b){
        int d1[10] = {0}, d2[10] = {0};
        while(a > 0 || b > 0){
            ++d1[a % 10];
            ++d2[b % 10];
            a /= 10;
            b /= 10;
        }
        
        
        for(int i = 9; i > 0; --i){
            if(d1[i] > 0 && d2[i] > 0)
                return true;
            if(d1[i] > 0 || d2[i] > 0)
                return false;
        }
        
        return false;
    }

public:
    int maxSum(vector<int> &nums){
        int ans = -1;
        
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < nums.size(); ++j){
                if(i == j)
                    continue;
                if(check(nums[i], nums[j]))
                    ans = max(ans, nums[i] + nums[j]);
            }
        }
        
        return ans;
    }
};
