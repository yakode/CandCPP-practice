class Solution{
public:
    int tribonacci(int n){
        int t[3] = {0, 1, 1};

        for(int i = 3; i <= n; ++i){
            t[i % 3] = t[2] + t[1] + t[0];
        }

        return t[n % 3];
    }
};
