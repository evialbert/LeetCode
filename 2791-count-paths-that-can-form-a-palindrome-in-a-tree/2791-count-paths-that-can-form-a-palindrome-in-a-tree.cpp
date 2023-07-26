class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        using ll = long long;
        using p = pair<int,char>;
        int n = parent.size();
        vector<vector<p>> AList(n);
        
        for(int i=1; i<n; i++) {
            AList[parent[i]].push_back({i, s[i]});
        }
        
        unordered_map<int,int> count;
        ll result = 0;
        
        function<void(int,int)> dfs = [&](int u, int bitmask) {
            result += count[bitmask];
            
            for(int i=0; i<26; i++) {
                result += count[bitmask ^ (1<<i)];
            }
            
            count[bitmask]++;
            
            for(auto& [v, ch] : AList[u]) {
                bitmask ^= (1<<(ch-'a'));
                
                dfs(v, bitmask);
                
                bitmask ^= (1<<(ch-'a'));
            }
        };
        
        dfs(0, 0);
        
        return result;
    }
};