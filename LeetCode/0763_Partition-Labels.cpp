class Solution{
public:
    vector<int> partitionLabels(string s){
        vector<int> ans;
        vector<vector<int>> pos(26, vector<int>(2, -1));

        for(int i = 0; i < s.size(); ++i){
            if(pos[s[i] - 'a'][0] == -1){
                pos[s[i] - 'a'][0] = i;
                pos[s[i] - 'a'][1] = i;
            }else{
                pos[s[i] - 'a'][1] = i;
            }
        }

        int tail = pos[s[0] - 'a'][1];
        int head = 0;
        for(int i = 1; i < s.size(); ++i){
            if(i > tail){
                ans.push_back(i - head);
                head = i;
            }

            if(pos[s[i] - 'a'][1] > tail)
                tail = pos[s[i] - 'a'][1];
        }
        ans.push_back(s.size() - head);

        return ans;
    }
};
