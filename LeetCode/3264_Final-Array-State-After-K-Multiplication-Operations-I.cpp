class Solution{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier){
        vector<int> ans(nums.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i = 0; i < nums.size(); ++i){
            pq.push({nums[i], i});
        }
        
        while(k--){
            pair<int, int> tmp;
            tmp.first = pq.top().first * multiplier;
            tmp.second = pq.top().second;
            pq.pop();
            pq.push(tmp);
        }

        for(int i = 0; i < nums.size(); ++i){
            ans[pq.top().second] = pq.top().first;
            pq.pop();
        }

        return ans;
    }
};
