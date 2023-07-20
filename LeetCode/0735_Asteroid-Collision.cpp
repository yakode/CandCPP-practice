class Solution{
    bool sign(int a){
        return a >= 0;
    }
    
public:
    vector<int> asteroidCollision(vector<int> &asteroids){
        vector<int> ans;
        stack<int> s;

        for(int i = 0; i < asteroids.size(); ++i){
            if(sign(asteroids[i])){
                s.push(asteroids[i]);
                continue;
            }

            bool flag = true;
            while(!s.empty() && sign(s.top())){
                if(abs(asteroids[i]) > abs(s.top())){
                    s.pop();
                }else if(abs(asteroids[i]) == abs(s.top())){
                    s.pop();
                    flag = false;
                    break;
                }else{
                    flag = false;
                    break;
                }
            }
            if(flag)
                s.push(asteroids[i]);
        }

        int n = s.size();
        ans.resize(n);
        while(!s.empty()){
            ans[--n] = s.top();
            s.pop();
        }

        return ans;
    }
};
