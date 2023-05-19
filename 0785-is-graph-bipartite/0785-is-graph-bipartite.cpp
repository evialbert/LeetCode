class Solution {
// Point to remember: A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B
// Here we are using the fact that in a bipartite graph no 2 adjacent nodes will be colored with the same color (1 or 0 for example)
private:
    bool checkIfBipartite(int current, vector<vector<int>> &graph, vector<int> &color) {
        if(color[current] == -1)   // not colored yet
            color[current] = 1;
        for(auto it : graph[current]) {  // search the adjacent nodes
            if(color[it] == -1) {  // not colored
                color[it] = 1 - color[current];  // colored with the opposite color
                if(!checkIfBipartite(it, graph, color))
                    return false;   // if we found out in any branch the graph is not bipartite
            } else if(color[it] == color[current])
                return false;  // if we found the adjacent ones colored with the same color
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; ++i) {
            if(!checkIfBipartite(i, graph, color))
                return false;
        }
        return true;
    }
};