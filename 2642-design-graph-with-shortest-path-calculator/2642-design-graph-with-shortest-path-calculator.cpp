class Graph {
public:
    vector<pair<int,int>> adj[100];
    int V;
    
    Graph(int n, vector<vector<int>>& edges) {
        //forming the graph
        V = n;
        for(auto edge : edges){
            adj[edge[0]].push_back({edge[1],edge[2]}); //u->{v,wt};
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        //for finding shortest path we will use djikstra's algorithm
        vector<int> distance(V,1e9);
        
        //min heap to store pair as {distance,node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        distance[node1] = 0;
        //push starting node with distance 0 to itself;
        pq.push({0,node1});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto x: adj[node]){
                int wt = x.second;
                int adjNode = x.first;
                
                //perform relaxation
                if(dis + wt < distance[adjNode]){
                    distance[adjNode] = dis + wt;
                    pq.push({distance[adjNode],adjNode});
                }
            }
        }

        return distance[node2] == 1e9 ?  -1 : distance[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */