class Solution {
public:
   unordered_map<int,vector<int>> adj1,adj2;

   void dfs(int node,int level,int par,int &evens,unordered_map<int,vector<int>> &adj){
    if(level%2==0)
    evens++;

    for(auto i:adj[node]){
        if(i!=par){
            dfs(i,level+1,node,evens,adj);
        }
    }
   }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;

        for(auto i:edges1){
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }

        for(auto i:edges2){
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }

        int evens=0;

        dfs(0,0,-1,evens,adj1);

        int evens2=0;

        dfs(0,0,-1,evens2,adj2);
        int odds2=m-evens2;

        vector<vector<int>> v(n,vector<int>(2,0));

        v[0][0]=evens;
        v[0][1]=n-evens;

        queue<pair<int,int>> q;

        q.push({0,-1});


        while(!q.empty()){
            auto [node,par]=q.front();
            q.pop();

            for(auto i:adj1[node]){
                if(i!=par){
                    v[i][0]=v[node][1];
                    v[i][1]=v[node][0];
                    q.push({i,node});
                }
            }
        }


        vector<int> ans;

        for(int i=0;i<n;i++){

           
            ans.push_back(v[i][0]+max(evens2,odds2));
        }


       return ans;

    }
};