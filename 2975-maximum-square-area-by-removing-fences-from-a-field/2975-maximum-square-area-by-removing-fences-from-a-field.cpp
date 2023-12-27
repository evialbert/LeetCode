class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& H, vector<int>& V) {
        int mod = 1E9 + 7;
        
        // also push boundries of vertical and horizontal frence
        H.push_back(1), H.push_back(m);
        V.push_back(1), V.push_back(n);
        
        // sort all horizontal frence and vertical frence
        sort(H.begin(), H.end());
        sort(V.begin(), V.end());
        
        // calculate all possible horizontal length for area with removing some h_frence
        unordered_set<int> h_len;
        for(int i = 0; i < H.size(); i++) {
            for(int j = i + 1; j < H.size(); j++) {
                h_len.insert(H[j] - H[i]);
            }
        }
        
        long long ans = -1;
        
         // calculate all possible vertical length for area with removing some h_frence
        for(int i = 0; i < V.size(); i++) {
            for(int j = i + 1; j < V.size(); j++) {
                int v_len = V[j] - V[i];
                // horizontal length match to vertical length then we make square with length v_len
                if(h_len.count(v_len)) ans = max(ans, v_len * 1ll * v_len);
            }
        }
        
        
        return ans % mod;
    }
};