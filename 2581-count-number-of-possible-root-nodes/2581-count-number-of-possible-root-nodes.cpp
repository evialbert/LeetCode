class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        const int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for(const auto& e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<unordered_set<int>> target(n);
        for(const auto& g : guesses)
            target[g[0]].insert(g[1]);
            
        int correct = 0;
        vector<bool> visited(n);
        
        function<void(int)> dfs = [&](int i){
            visited[i] = true;
            for(int c : g[i]){
                if(visited[c]) continue;
                if(target[i].count(c) > 0)
                    ++correct;
                dfs(c);
            }
        };
        dfs(0);
        
        int res = 0;
        fill(visited.begin(), visited.end(), false);
        function<void(int)> recursion = [&](int i){
            visited[i] = true;        
            if(correct >= k) ++res;
            for(int c : g[i]){
                if(visited[c]) continue;
                const int correct_cp = correct;

                if(target[i].count(c) > 0) --correct;
                if(target[c].count(i) > 0) ++correct;
                
                recursion(c);
                correct = correct_cp;
            }  
        };
        
        recursion(0);
        return res;
    }
};