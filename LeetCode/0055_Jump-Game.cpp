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

class Solution{
public:
    bool canJump(vector<int> &nums){
        if(nums.size() == 1)
            return true;

        int i = 0, j = nums[0];

        while(i <= j){
            if(i >= nums.size() - 1)
                return true;
            if(i == j && nums[i] == 0)
                return false;
            j = max(j, i + nums[i]);
            ++i;
        }

        return false;
    }
};
