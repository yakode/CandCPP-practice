class Solution{
    void dfs(int i, string &num, long long int n1, long long int n2, long long int n3, bool &ans){
        if(ans)
            return;
        if(i == num.size()){
            if(n1 >= 0 && n2 >= 0 && n3 >= 0)
                ans = true;
            return;
        }

        for(int j = i; j < num.size(); ++j){
            // a + b = c is impossible, if b > a and b > c 
            if(i < j - i + 1 && j - i + 1 > num.size() - j)
                break;
            
            long long int tmp = stoll(num.substr(i, j - i + 1));
            if(n1 >= 0 && n2 >= 0){
                if(n1 + n2 == tmp){
                    dfs(j + 1, num, tmp, n1, n2, ans);
                }
            }else{
                dfs(j + 1, num, tmp, n1, n2, ans);
            }

            // 0(\d)+ is invalid
            if(tmp == 0)
                break;
        }
    }

public:
    bool isAdditiveNumber(string num){
        if(num.size() < 3)
            return false;

        bool ans = 0;

        dfs(0, num, -1, -1, -1, ans);

        return ans;
    }
};
