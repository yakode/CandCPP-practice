class Solution{
    int check(string word){
        if(word[0] != 'a' 
            && word[0] != 'e'
            && word[0] != 'i'
            && word[0] != 'o'
            && word[0] != 'u')
            return 0;
        if(word[word.size() - 1] != 'a' 
            && word[word.size() - 1] != 'e'
            && word[word.size() - 1] != 'i'
            && word[word.size() - 1] != 'o'
            && word[word.size() - 1] != 'u')
            return 0;
        return 1;
    }

public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries){
        vector<int> ans(queries.size(), 0);
        vector<int> prefixSum(words.size() + 1, 0);

        prefixSum[0] = check(words[0]);
        for(int i = 1; i < words.size(); ++i){
            prefixSum[i] = prefixSum[i - 1] + check(words[i]);
        }

        for(int i = 0; i < queries.size(); ++i){
            if(queries[i][0] == 0)
                ans[i] = prefixSum[queries[i][1]];
            else
                ans[i] = prefixSum[queries[i][1]] - prefixSum[queries[i][0] - 1];
        }

        return ans;
    }
};
