class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0); 
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);

        if (rootI != rootJ) {
            
            if (rank[rootI] > rank[rootJ]) {
                parent[rootJ] = rootI;
            } else if (rank[rootI] < rank[rootJ]) {
                parent[rootI] = rootJ;
            } else {
                parent[rootJ] = rootI;
                rank[rootI]++;
            }
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n+1);
        for(auto i : edges){
            int p1 = uf.find(i[0]);
            int p2 = uf.find(i[1]);
            if(p1==p2){
                return i;
            }else{
                uf.unite(i[0], i[1]);
            }
        }
        
        return {};
    }
};