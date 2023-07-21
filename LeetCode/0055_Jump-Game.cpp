class Solution{
public:
    bool canJump(vector<int> &nums){
        if(nums.size() == 1)
            return true;
            
        vector<bool> isVisited(nums.size(), false);
        stack<int> s;
        
        s.push(0);
        isVisited[0] = true;
        while(!s.empty()){
            int x = s.top();
            s.pop();
            for(int i = 1; i <= nums[x]; ++i){
                if(x + i == nums.size() - 1)
                    return true;
                if(!isVisited[x + i]){
                    s.push(x + i);
                    isVisited[x + i] = true;
                }
            }
        }

        return false;
    }
};
