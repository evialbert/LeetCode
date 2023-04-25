class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> distances(n, INT_MAX);
        for (int x: banned) {
            distances[x] = -1;
        }
        
        vector<int> nodes, new_nodes;
        distances[p] = 0;
        nodes.push_back(p);
        
        while (nodes.size()) {
            int i_min = INT_MAX;
            int i_max = INT_MIN;
            
            for (int node: nodes) {
                int base = node - k + 1;
                
                // j: segment start position
                // i: update position
                auto j2i = [=](int j) {
                    return base + (j - base) * 2;
                };
                
                auto update = [&](int i) {
                    if (distances[i] == INT_MAX) {
                        distances[i] = distances[node] + 1;
                        new_nodes.push_back(i);
                    }
                };
                
                // inclusive
                int lo = j2i(max(0, base));
                int hi = j2i(min(node + k, n) - k);
                for (int i = lo; i <= min(hi, i_min-2); i += 2) update(i);
                for (int i = max(lo, i_max+2); i <= hi; i += 2) update(i);
                i_min = min(i_min, lo);
                i_max = max(i_max, hi);
            }
            
            swap(nodes, new_nodes);
            new_nodes.clear();
        }
        
        for (int &x: distances) {
            if (x == INT_MAX) x = -1;
        }
        return distances;
    }
};