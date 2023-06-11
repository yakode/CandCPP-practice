// shit code and shit type problem = =
class Solution{
public:
    long long minCost(vector<int> &nums, int x){
        unsigned long long ans = LLONG_MAX;
        
        unsigned long long hi[1001][2] = {0};
    
        for(int i = 0; i < nums.size(); ++i){
            unsigned long long tmp = (unsigned long long)x * i;
            for(int j = 0; j < nums.size(); ++j){
                if(hi[j][0] == false){
                    hi[j][0] = true;
                    hi[j][1] = nums[(j+nums.size()-i)%nums.size()];
                    tmp += hi[j][1];
                }else{
                    if(hi[j][1] > nums[(j+nums.size()-i)%nums.size()]){
                        hi[j][1] = nums[(j+nums.size()-i)%nums.size()]; 
                    }
                    tmp += hi[j][1];
                }
            }
            ans = min(ans, tmp);
        }
        
        return ans;
    }
};
