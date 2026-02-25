class Solution {
public:
    vector<int> bit;

    // Helper to add value to BIT
    void add(int ind, int val) {
        ind++; // 1-based indexing for BIT
        while (ind < bit.size()) {
            bit[ind] += val;
            ind += (ind) & (-ind);
        }
    }

    // Helper to get prefix sum from BIT
    int query(int ind) {
        ind++; // 1-based indexing for BIT
        int sum = 0;
        while (ind > 0) {
            sum += bit[ind];
            ind -= (ind) & (-ind);
        }
        return sum;
    }

    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n = s.size();
        bit.assign(n + 1, 0);

        // Lambda to check if a specific index creates a conflict (defect)
        // A defect exists at index i if s[i] == s[i+1]
        auto defect = [&](int i) {
            if (i < 0 || i >= n - 1) return 0;
            return s[i] == s[i + 1] ? 1 : 0;
        };

        // Build initial BIT
        for (int i = 0; i < n - 1; i++) {
            if (defect(i)) add(i, 1);
        }

        vector<int> ans;
        for (auto it : queries) {
            if (it[0] == 1) {
                // Update Operation
                int j = it[1];
                
                // 1. Remove old contributions of adjacent pairs
                int left = defect(j - 1), right = defect(j);
                if (left) add(j - 1, -1);
                if (right) add(j, -1);

                // 2. Perform the flip
                s[j] = s[j] == 'A' ? 'B' : 'A';

                // 3. Add new contributions of adjacent pairs
                int newLeft = defect(j - 1), newRight = defect(j);
                if (newLeft) add(j - 1, 1);
                if (newRight) add(j, 1);
            } 
            else {
                // Query Operation
                int l = it[1], r = it[2];
                if (l >= r) {
                    ans.push_back(0); // Single char is always alternating
                } else {
                    // We need the number of defects in range [l, r-1]
                    // Because defect at index i compares s[i] and s[i+1]
                    ans.push_back(query(r - 1) - query(l - 1));
                }
            }
        }
        return ans;
    }
};