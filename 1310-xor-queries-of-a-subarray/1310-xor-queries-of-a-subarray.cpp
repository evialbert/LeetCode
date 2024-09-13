class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXor(n);
        prefixXor[0] = arr[0];

        for (int i = 1; i < n; i++) {
            prefixXor[i] = prefixXor[i - 1] ^ arr[i];
        }

        int q = queries.size();
        vector<int> ans(q);
        
        for (int i = 0; i < q; i++) {
            int L = queries[i][0];
            int R = queries[i][1];
            
            if (L == 0) {
                ans[i] = prefixXor[R];
            } else {
                ans[i] = prefixXor[R] ^ prefixXor[L - 1];
            }
        }
        
        return ans;
    }
};