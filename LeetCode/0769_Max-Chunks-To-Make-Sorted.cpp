class Solution{
public:
    int maxChunksToSorted(vector<int>& arr){
        int ans = 0;
        stack<int> s;
        
        for(int i = 0; i < arr.size(); ++i){
            if(arr[i] > i)
                s.push(arr[i]);
            while(!s.empty() && s.top() <= i)
                s.pop();
            if(s.empty())
                ++ans;
        }

        return ans;
    }
};
