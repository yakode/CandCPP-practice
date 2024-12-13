class Solution{
public:
    long long findScore(vector<int> &nums){
        long long ans = 0;
        priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
        vector<bool> marked(nums.size() + 2, false);

        for(int i = 0; i < nums.size(); ++i){
            pq.push({nums[i], i + 1});
        }

        while(!pq.empty()){
            int id = pq.top().second;
            if(!marked[id]){
                ans += pq.top().first;
                marked[id] = true;
                marked[id - 1] = true;
                marked[id + 1] = true;
            }
            pq.pop();
        }

        return ans;
    }
};
