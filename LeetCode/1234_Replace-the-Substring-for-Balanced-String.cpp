class Solution{
public:
    int balancedString(string s){
        int ans = s.size();
        int n = s.size() / 4;
        vector<int> cnt(26, -n); // QWER

        for(int i = 0; i < s.size(); ++i){
            cnt[s[i] - 'A']++;
        }

        int left = 0;
        for(int right = 0; right < s.size(); ++right){
            cnt[s[right] - 'A']--;

            while(left <= right && cnt[s[left] - 'A'] < 0){
                cnt[s[left] - 'A']++;
                left++;
            }

            if(cnt['Q' - 'A'] <= 0 && cnt['W' - 'A'] <= 0 && cnt['E' - 'A'] <= 0 && cnt['R' - 'A'] <= 0){
                ans = min(ans, right - left + 1);
            }
        }

        return ans;
    }
};
