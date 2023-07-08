class Solution{
public:
    long long putMarbles(vector<int> &weights, int k){
        long long ans = 0;
        vector<int> cost(weights.size() - 1, 0);

        for(int i = 0; i < cost.size(); ++i){
            cost[i] = weights[i] + weights[i + 1];
        }
        sort(cost.begin(), cost.end());

        for(int i = 0; i < k - 1; ++i){
            ans -= cost[i];
            ans += cost[cost.size() - 1 - i];
        }

        return ans;
    }
};
