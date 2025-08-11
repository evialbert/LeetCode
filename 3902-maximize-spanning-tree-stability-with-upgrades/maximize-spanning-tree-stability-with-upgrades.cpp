class Solution {
    struct DSU{
        int totalNode;
        vector<int> parent;
        vector<int> size;
        DSU(int n){
            totalNode = n;
            size.resize(n,1);
            parent.resize(n);
            for(int i=0; i<n; ++i)
                parent[i] = i;
        }
        int find(int ind){
            if(parent[ind] != ind)
                parent[ind] = find(parent[ind]);
            return parent[ind];
        }
        bool merge(int n1, int n2){
            int G1 = find(n1);
            int G2 = find(n2);
            if(G1 == G2) return false;
            if(size[G2] > size[G1]) swap(G1, G2);
            parent[G2] = G1;
            size[G1] += size[G2];
            --totalNode;
            return true;
        }
    };
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        // Use Kruskal’s but choose the biggest
        DSU dsu(n);
        int minStrength = INT_MAX;
        vector<int> candEdge; // record candidate index
        // 1. Pick the must edge first
        for(int ind = 0; ind < edges.size(); ++ind){
            vector<int>& edge = edges[ind];
            if(edge[3] == 0){
                candEdge.push_back(ind);
            } else {
                minStrength = min(minStrength, edge[2]);
                if(dsu.merge(edge[0], edge[1]) == false)
                    return -1; // have cycle
            }
        }
        sort(candEdge.begin(), candEdge.end(), [&](int a, int b){
            return edges[a][2] > edges[b][2];
        });
        // 2. Pick the biggest edge in candidate first
        vector<int> pickStrength;
        for(auto index : candEdge){
            int u = edges[index][0];
            int v = edges[index][1];
            if(dsu.merge(u, v)){
                pickStrength.push_back(edges[index][2]);
                if(dsu.totalNode == 1) break;
            }
        }
        // 3. Upgrade the k weakest selected edges to double their strength.
        if(k && !pickStrength.empty())
            minStrength = min(minStrength, pickStrength.back()*2);
        if(pickStrength.size() > k)
            minStrength = min(minStrength, pickStrength[pickStrength.size() - 1 - k]);
        return dsu.totalNode == 1 ? minStrength : -1;
    }
};