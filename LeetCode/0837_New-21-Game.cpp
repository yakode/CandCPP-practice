class Solution{
public:
    double new21Game(int n, int k, int maxPts){
        double w[20000] = {0};
        double wSum = n - k + 1;

        if(wSum > maxPts){
            wSum = maxPts;
        }

        for(int i = k; i <= n; ++i){
            w[i] = 1;
        }

        for(int i = k-1; i >= 0; --i){
            w[i] = wSum / maxPts;
            wSum -= w[i + maxPts];
            wSum += w[i];
        }

        return w[0];
    }
};
