// not good but mine :)
class Solution{
public:
    // dp[w][m][i]
    // w == 0 --> Alice
    // w == 1 --> Bob
    // pair.first --> score of Alice
    // pair.second --> score of Bob
    pair<int, int> dp[2][205][105];

    pair<int, int> dfs(int i, int m, vector<int> &piles, int who){
        // who == 1 --> Alice
        // who == -1 --> Bob
        
        if(i == piles.size()) return make_pair(0, 0);

        if(who == 1 && dp[0][m][i].first > 0) return dp[0][m][i];
        if(who == -1 && dp[1][m][i].second > 0) return dp[1][m][i];

        int sum = 0;
        pair<int, int> ret, maxi(0, 0);
        for(int x = 1; x <= 2*m && (i + x) <= piles.size(); ++x){
            ret = dfs(i + x, max(m, x), piles, who*-1);

            sum += piles[i + x - 1];
            if(who == 1){
                ret.first += sum;
                if(ret.first > maxi.first) maxi = ret;
            }else{
                ret.second += sum;
                if(ret.second > maxi.second) maxi = ret;
            }
        }

        if(who == 1) return dp[0][m][i] = maxi;
        return dp[1][m][i] = maxi;
    }

    int stoneGameII(vector<int> &piles){
        for(int i = 0; i < piles.size(); ++i){
            for(int j = 0; j < piles.size(); ++j){
                dp[0][i][j] = make_pair(0, 0);
                dp[1][i][j] = make_pair(0, 0);
            }
        }
        
        return dfs(0, 1, piles, 1).first;
    }
};

// Alice maximize her score, and Bob minimize Alice's score
// slower than my ugly solution, IDK the reason
class Solution{
public:
    int dp[2][205][105] = {0};

    int dfs(int i, int m, vector<int> &piles, int who){
        if(i == piles.size()) return 0;

        if(dp[who][m][i] > 0) return dp[who][m][i];

        int sum = 0;
        int ret, tmp = who? 0: INT_MAX;
        for(int x = 1; x <= 2*m && (i + x) <= piles.size(); ++x){
            sum += piles[i + x - 1];
            ret = dfs(i + x, max(m, x), piles, who^1);

            if(who) tmp = max(tmp, ret + sum);
            else tmp = min(tmp, ret);
        }

        return dp[who][m][i] = tmp;
    }

    int stoneGameII(vector<int> &piles){
        return dfs(0, 1, piles, 1);
    }
};
