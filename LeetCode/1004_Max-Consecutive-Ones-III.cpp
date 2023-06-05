class Solution{
public:
    int longestOnes(vector<int> &nums, int k){
        int ans = 0;
        int left = 0;
        int flip = 0;

        for(int right = 0; right < nums.size(); ++right){
            if(nums[right] == 0){
                if(flip < k){
                    flip++;
                }else{
                    while(left <= right && nums[left++] != 0);
                }
            }
            ans = max(ans, (right - left + 1));
        }

        return ans;
    }
};
