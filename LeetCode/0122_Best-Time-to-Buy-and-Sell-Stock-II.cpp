class Solution{
public:
    int maxProfit(vector<int> &prices){
        int ans = 0;
        int buy = prices[0];

        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] < prices[i - 1]){
                if(prices[i - 1] > buy){
                    ans += prices[i - 1] - buy;
                }
                buy = prices[i];
            }
        }
        if(prices[prices.size() - 1] > buy)
            ans += prices[prices.size() - 1] - buy;

        return ans;
    }
};
