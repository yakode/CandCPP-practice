class Solution{
public:
    vector<int> finalPrices(vector<int> &prices){
        vector<int> ans(prices);
        stack<int> buf;

        buf.push(0);
        for(int i = 1; i < prices.size(); ++i){
            while(!buf.empty() && prices[i] <= prices[buf.top()]){
                ans[buf.top()] -= prices[i];
                buf.pop();
            }
            buf.push(i);
        }

        return ans;
    }
};
