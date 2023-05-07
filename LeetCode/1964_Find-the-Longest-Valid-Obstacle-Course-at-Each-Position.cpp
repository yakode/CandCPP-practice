class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans(obstacles.size(), 0);
        ans[0] = 1;

        // idk[i] means the minimum ending height for the obstacle course with the length i
        vector<int> idk(obstacles.size()+1, 1e8);
        idk[0] = 0;
        idk[1] = obstacles[0];

        int max_len = 1;

        for(int i = 1; i < obstacles.size(); ++i){
            ans[i] = 1;

            int left = 0, right = max_len + 1, middle;
            while(left < right){
                middle = left + (right - left) / 2;
                if(idk[middle] <= obstacles[i]){
                    left = middle + 1;
                }else{
                    right = middle;
                }
            }
            
            ans[i] = left;
            if(idk[left] > obstacles[i]) idk[left] = obstacles[i];
            if(left > max_len) max_len = left;
        }

        return ans;
    }
};
