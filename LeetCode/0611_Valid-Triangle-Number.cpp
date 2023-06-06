class Solution{
public:
    int triangleNumber(vector<int> &nums){
        int ans = 0;

        sort(nums.begin(), nums.end());

        for(int i = nums.size()-1; i >= 0; --i){
            int j = 0, k = i - 1;

            while(j < k){
                int sum = nums[j] + nums[k];

                if(sum <= nums[i]){
                    j++;
                }else{
                    ans += (k - j);
                    k--;
                }
            }
        }

        return ans;
    }
};
