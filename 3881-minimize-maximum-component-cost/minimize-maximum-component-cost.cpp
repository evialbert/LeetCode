struct comp{
    bool operator()(const vector<int>&a, const vector<int>&b){
        return a[2] < b[2];
    }
};
class Solution {
private:
    int find(vector<int>& parent, int node) {
        if (parent[node] == -1 || parent[node] == node)
            return node;

        return parent[node] = find(parent, parent[node]);
    }

    void union_(vector<int>& parent, vector<int>& size, int x, int y) {
        int findPx = find(parent, x);
        int findPy = find(parent, y);
        if (size[findPx] >= size[findPy]) {
            size[findPx]++;
            parent[findPy] = findPx;
        } else {
            size[findPy]++;
            parent[findPx] = findPy;
        }
    }

public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        if(n<=k)
            return 0;

        int ans = 0, p_x, p_y;
        vector<int>parent(n);
        vector<int>size(n, 0);
        unordered_set<int>parentSt;

        sort(edges.begin(), edges.end(), comp());

        for(int i=0;i<n;i++){
            parent[i] = i;
            parentSt.insert(i);
            // Initially we have n components
        }

        for(auto x:edges){
            ans = max(ans, x[2]);
            p_x = find(parent, x[0]);
            p_y = find(parent, x[1]);

            //Remove previous parents as the union is about to happen
            parentSt.erase(p_x);
            parentSt.erase(p_y);

            union_(parent, size, p_x, p_y);

            //Inserting new final parent
            parentSt.insert(find(parent, p_x));
            
            if(parentSt.size() == k) //We got all k components now
                break;
        }

        return ans;
    }
};