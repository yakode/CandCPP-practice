class Solution{
    bool check(long long t, int n, vector<int> &batteries){
        long long sum = 0;
        
        for(auto &i: batteries){
            if(i > t)
                sum += t;
            else
                sum += i;
        }

        return sum >= (t * n);
    }

public:
    long long maxRunTime(int n, vector<int> &batteries){
        long long left = 0, right = LLONG_MAX / n, middle;

        while(left < right){
            middle = left + (right - left) / 2;
            if(check(middle, n, batteries)){
                left = middle + 1;
            }else{
                right = middle;
            }
        }

        return left - 1;
    }
};
