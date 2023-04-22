class Solution {
public:
    int dp[505][505];

    int dfs(int l, int r, string &s){
        if(dp[l][r] >= 0) return dp[l][r];

        if(l == r) return dp[l][r] = 0;

        if(s[l] == s[r]){
            if(l+1 == r) return dp[l][r] = 0;
            return dp[l][r] = dfs(l+1, r-1, s);
        }else{
            return dp[l][r] = min(dfs(l, r-1, s), dfs(l+1, r, s))+1;
        }
    }

    int minInsertions(string s) {
        memset(dp, -1 , sizeof(dp));
        return dfs(0, s.size()-1, s);
    }
};

// Thank you Finesse for the tip left in the discussion area!
/*
 * Finesse:
 *
 *	 It's very easy to solve with a simple dynamic programming:
 *	
 *		1. Use 2 pointers to walk from the string edges towards the center.
 *		2. When the letters at the pointers don't match, you can
 *		   either add a letter on the left or add a letter on the right. 
 *		   In both cases you get a smaller problem
 *		   (finding a solution for a substring).
 *		3. Solve both smaller problems recursively and choose the best result.
 *	
 *	 No need to know anything about the longest common subsequence algorithm, 
 *	 which is much harder.
 */
