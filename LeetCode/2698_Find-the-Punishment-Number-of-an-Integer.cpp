class Solution{
    bool check(int i, string n, int sum){
        if(i == n.size()){
            if(sum == sqrt(stoi(n))){
                return true;
            }else{
                return false;
            }
        }

        bool ret = false;
        for(int j = i; j < n.size(); ++j){
            int tmp = stoi(n.substr(i, j - i + 1));
            ret |= check(j + 1, n, sum + tmp);
            if(ret)
                return true;
        }

        return false;
    }

public:
    int punishmentNumber(int n){
        int ans = 0;

        for(int i = 1; i <= n; ++i){
            int i2 = i * i;
            if(check(0, to_string(i2), 0))
                ans += i2;
        }

        return ans;
    }
};
