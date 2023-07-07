class Solution{
public:
    int maxConsecutiveAnswers(string answerKey, int k){
        int ans = 0;
        queue<int> q;

        for(int left = 0, right = 0; right < answerKey.size(); ++right){
            if(answerKey[right] == 'F'){
                if(q.size() == k){
                    left = q.front() + 1;
                    q.pop();
                }
                q.push(right);
            }
            ans = max(ans, right - left + 1);
        }
        while(!q.empty()) q.pop();
        for(int left = 0, right = 0; right < answerKey.size(); ++right){
            if(answerKey[right] == 'T'){
                if(q.size() == k){
                    left = q.front() + 1;
                    q.pop();
                }
                q.push(right);
            }
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};
