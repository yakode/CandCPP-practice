class Solution{
    double cal(vector<int> &dist, int speed){
        double ret = 0;

        for(int i = 0; i < dist.size() - 1; ++i){
            ret += ceil(double(dist[i]) / speed);
        }
        ret += double(dist[dist.size() - 1]) / speed;

        return ret;
    }
    
public:
    int minSpeedOnTime(vector<int> &dist, double hour){
        long long int left = 1, right = INT_MAX, middle;
        int ans = -1;

        while(left < right){
            middle = left + (right - left) / 2;
            double ret = cal(dist, middle);
            if(ret > hour)
                left = middle + 1;
            else if(ret == hour)
                return middle;
            else{
                ans = right;
                right = middle;
            }
            if(left == right && cal(dist, left) <= hour){
                return left;
            }
        }

        return ans;
    }
};
