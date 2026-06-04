class Solution {
public:

    template <typename T>
        void out(const std::vector<T>& vec) {
            for (const auto& element : vec) {
                cout << element << ' ';
            } cout << endl ;
            //cout << endl ;
        }

        void  dfs(int node , vector<vector<int>>& adj , vector<int>& visited){
            if(visited[node]) return ;
            visited[node] = 1 ;
            for(auto& x : adj[node]){
                if(!visited[x]) dfs(x , adj , visited);
            }
            return ;
        }
    
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges){
        int n = nums.size();

        vector<vector<int>> adj(n);

        for(auto& E : edges){
            int x = E[0] , y = E[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> visited(n , -1);
        int ans = 0  ;
        
        for(int i = 1 ; i < (1ll << n) ; i++){

            for(int k = 0 ; k < n ; k++) visited[k] = -1 ;

            vector<int> res ;
            int sum = 0 ;
            for(int bit = 0 ; bit < n ; bit++){
                if((i & (1ll << bit))){
                    res.push_back(bit);
                    visited[bit] = 0 ; // careful as we only have to consider nodes in the subset only
                    sum += nums[bit];
                }
            }

            dfs(res[0] , adj , visited);

            int all = 0  ;

            for(int i = 0  ;i < n ; i++){
                if(visited[i] == 1) all += 1 ; // visited[i] == 1 check only the nodes visited by dfs in our subset of nodes we don't want to consider nodes of original graph
            }

            if(all == res.size() && sum % 2 == 0) ans += 1;
        }
        return ans ;
    }
};