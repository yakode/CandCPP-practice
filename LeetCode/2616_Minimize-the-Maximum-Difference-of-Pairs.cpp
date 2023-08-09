class Solution{
public:
    int minimizeMax(vector<int> &nums, int p){
        int left = 0, right = INT_MAX, middle;

        sort(nums.begin(), nums.end());

        while(left < right){
            middle = left + (right - left) / 2;

            int cnt = 0;
            for(int i = 0; i < nums.size() - 1; ++i){
                if(nums[i + 1] - nums[i] <= middle){
                    ++cnt;
                    ++i;
                }
            }
            if(cnt >= p)
                right = middle;
            else
                left = middle + 1;
        }

        return right;
    }
};
