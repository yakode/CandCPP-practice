class Solution{
public:
    int singleNumber(vector<int> &nums){
        int one = 0, two = 0;

        for(auto &i: nums){
            one = (one ^ i) & ~two;
            two = (two ^ i) & ~one;
        }

        return one;
    }
};
