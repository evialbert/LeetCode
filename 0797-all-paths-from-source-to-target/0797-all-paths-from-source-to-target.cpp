class Solution {
public:
    int start, end;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        start=0, end=graph.size()-1; 
        
        vector<vector<int>> store;
        vector <int> path;
        
        dfs(store, path, graph);
        
        return store;
    }
    
    void dfs(vector<vector<int>>& store, vector <int> &path, vector<vector<int>> graph, int start=0){
        path.push_back(start);
        
        if(start == end){
            store.push_back(path);
            path.pop_back();
            return;
        }
        
        for(auto& s : graph[start])
            dfs(store, path, graph, s);

        path.pop_back();
    }
};