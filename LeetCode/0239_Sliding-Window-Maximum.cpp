class Solution{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k){
        vector<int> ans;
        vector<pair<int, int>> h;

        for(int i = 0; i < k - 1; ++i){
            h.push_back(make_pair(nums[i], i));
        }
        make_heap(h.begin(), h.end());

        for(int i = k - 1; i < nums.size(); ++i){
            h.push_back(make_pair(nums[i], i));
            push_heap(h.begin(), h.end());

            while(1){
                pair<int, int> tmp = h.front();
                if(tmp.second >= i - k + 1){
                    ans.push_back(tmp.first);
                    break;
                }else{
                    pop_heap(h.begin(), h.end());
                    h.pop_back();
                }
            }
        }
        
        return ans;
    }
};
