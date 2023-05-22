// bucket sort
class Solution{
public:
    vector<int> topKFrequent(vector<int> &nums, int k){
        vector<int> ans;
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for(int i = 0; i < nums.size(); ++i){
            count[nums[i]]++;
        }

        for(const auto &it: count){
            freq[it.second].push_back(it.first);
        }

        for(int i = nums.size(); i >= 0, ans.size() < k; --i){
            if(freq[i].size() > 0){
                ans.insert(ans.end(), freq[i].begin(), (ans.size() + freq[i].size()) <= k? freq[i].end(): freq[i].begin() + (k - ans.size()));
            }
        }

        return ans;
    }
};

// sorting
class Solution{
public:
    vector<int> topKFrequent(vector<int> &nums, int k){
        vector<int> ans(k);
        vector<pair<int, int>> compressed;

        sort(nums.begin(), nums.end());
        int cur = nums[0];
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == cur){
                cnt ++;
            }else{
                compressed.push_back(make_pair(cur, cnt));
                cur = nums[i];
                cnt = 1;
            }
        }
        compressed.push_back(make_pair(cur, cnt));

        sort(compressed.begin(), compressed.end(), [](pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        });
        for(int i = 0; i < k; ++i)
            ans[i] = compressed[i].first;

        return ans;
    }
};
