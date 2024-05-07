class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int N = word.size();
        
        map<string, int> count;
        
        for(int i=0; i<=N-k; i+=k) {
            count[word.substr(i, k)]++;
        }
        
        int mx = 0;
        for(auto e : count) {
            mx = max(mx, e.second);
        }
        
        return N/k - mx;
    }
};