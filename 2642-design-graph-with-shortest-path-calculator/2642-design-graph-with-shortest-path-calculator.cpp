class Graph {
public:
    vector<vector<pair<int,int>>>adj_graph;
    Graph(int n, vector<vector<int>>& edges) {        
        adj_graph.resize(n);
        for(auto edge:edges){
            adj_graph[edge[0]].push_back({edge[1],edge[2]});
        }
        
    }
    
    void addEdge(vector<int> edge) {
        adj_graph[edge[0]].push_back({edge[1],edge[2]});
        
    }
    int shortestPath(int node1, int node2) {   
        int n= adj_graph.size();
        vector<int>dist(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,node1});
        dist[node1]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int pdist=pq.top().first;
            pq.pop();
            if(node==node2)return pdist;
            for(auto ngh:adj_graph[node]){
                int curdist=ngh.second;
                int adjnode=ngh.first;
                if(curdist+pdist<dist[adjnode]){
                    dist[adjnode]=curdist+pdist;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */