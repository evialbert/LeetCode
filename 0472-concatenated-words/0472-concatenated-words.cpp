class Solution {
public:
    vector<string> res;
    void findPart(unordered_set<string> & words_set, string word){
        int n = word.size();
        vector<bool> dp(n + 1, 0);
        dp[0] = 1;
        for(int i=0; i<n; i++){
            if(!dp[i]) continue; // no substr can split at here 
            for(int j=i+1; j<=n; j++){                
                string tmp = word.substr(i,j-i);
                if(j-i < n && words_set.count(tmp)) dp[j] = 1; // we only test for shorter substr 
            }
            if(dp[n]) {
                res.push_back(word);
                break;
            }
        }
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // unordered_set used for unique elements without any specific ordering
        unordered_set<string> words_set(words.begin(), words.end());
        for(int i=0; i<words.size(); i++) findPart(words_set, words[i]);
        return res;
    }
};