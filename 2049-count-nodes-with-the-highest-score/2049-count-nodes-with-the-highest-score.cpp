class Solution {
public:
    long long N;
    long long maxi;
    long long count;
    int dfs(vector<vector<int>>& g, int src){
        
        int l = 0,r = 0;
        
        if(g[src].size() > 0){
            l = dfs(g,g[src][0]);
        }
        
        if(g[src].size() > 1){
            r = dfs(g,g[src][1]);
        }
        
        long long res = 1;
        
        if(l)res *= l;
        if(r)res *= r;
        
        long long left = N-(l+r)-1;
        
        if(left)res *= left;
        if(maxi < res){
            count=1;
            maxi=res;
        }
        
        else if(maxi == res){
            count++;
        }
        
        return l+r+1;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        
        int n = size(parents);
        
        maxi = -1;
        count = 0;
        N=n;
        
        vector<vector<int>> g(n);
        
        for(int i = 1; i < n; i++){
            
            g[parents[i]].push_back(i);
        }
        
        dfs(g,0);
        
        return count;
    }
};