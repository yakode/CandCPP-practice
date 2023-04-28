class Solution {
public:
    int root[300];

    int find(int i){
        if(root[i] == i) return i;

        return root[i] = find(root[i]);
    }

    bool isSimilar(string &x, string &y){
        int cnt = 2;

        for(int i = 0; i < x.size(); ++i){
            if(x[i] != y[i]){
                --cnt;
                if(cnt < 0) return false;
            }
        }
            

        return (cnt >= 0);
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int ans = strs.size();

        for(int i = 0; i < strs.size(); ++i)
            root[i] = i;

        for(int i = 0; i < strs.size(); ++i){
            for(int j = i + 1; j < strs.size(); ++j){
                if(find(i) != find(j)){
                    if(isSimilar(strs[i], strs[j])){
                        root[root[i]] = root[j];
                        --ans;
                    }
                }
            }
        }

        return ans;
    }
};
