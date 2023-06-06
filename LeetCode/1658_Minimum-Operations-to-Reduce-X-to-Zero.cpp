class Solution{
public:
    int minOperations(vector<int> &nums, int x){
        int ans = nums.size() + 1;
        int left = 0, right = nums.size() - 1;
        
        while(x > 0 && left <= right){
            x -= nums[left++];
        }

        if(x == 0) ans = left;

        for(; right >= left; --right){
            x -= nums[right];

            while(x < 0 && left > 0){
                x += nums[--left];
            }

            if(x == 0){
                // [0, left), [right, nums.size)
                ans = min(ans, (left + (int)(nums.size() - right)));
            }
        }

        return (ans == nums.size() + 1)? -1: ans;
    }
};
