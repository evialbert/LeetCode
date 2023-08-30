class Solution {
private:
    void dfs(vector<vector<int>>&adj,vector<bool>&visited,int node){
        visited[node]=true;

        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node].at(i)]) dfs(adj,visited,adj[node].at(i));
        }
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(numCourses);
        set<pair<int,int>>s;
        vector<bool>ans;

        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites.at(i)[0];
            int v=prerequisites.at(i)[1];

            adj[v].push_back(u);
        }

        for(int i=0;i<numCourses;i++){
            vector<bool>visited(numCourses,false);
            dfs(adj,visited,i);

            for(int j=0;j<numCourses;j++){
                if(i!=j && visited[j]){
                    s.insert({j,i});
                }
            }
        }

        for(int i=0;i<queries.size();i++){
            int u=queries.at(i)[0];
            int v=queries.at(i)[1];

            if(s.count({u,v})) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};