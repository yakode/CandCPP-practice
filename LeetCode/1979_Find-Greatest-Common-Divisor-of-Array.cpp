class Solution{
public:
    int gcd(int x, int y){
        while(x != 0 && y != 0){
            if(x > y) x -= y;
            else y -= x;
        }

        return x + y;
    }

    int findGCD(vector<int>& nums){
        int max_num = nums[0], min_num = nums[0];

        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > max_num) max_num = nums[i];
            if(nums[i] < min_num) min_num = nums[i];
        }

        return gcd(max_num, min_num);
    }
};
