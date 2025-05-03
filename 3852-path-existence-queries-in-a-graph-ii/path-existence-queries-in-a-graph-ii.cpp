class Solution {
public:
    int findkthParent(int ind, int k, vector<vector<int>> & par) {
        int ans = ind;
        for(int i = 19; i >= 0; i --) {
            if(ans == -1) return ans;
            if((1 << i) & k) {
                ans = par[ans][i];
            }
        }
        return ans;
    }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> node_with_values;
        vector<int> reverse_index(n);
        for(int i = 0; i < nums.size(); i ++) {
            node_with_values.push_back({nums[i], i});
        }

        sort(node_with_values.begin(), node_with_values.end());

        for(int i = 0; i < n; i ++) {
            reverse_index[node_with_values[i][1]] = i;
        }



        // mo's algorithm. sqrt decomposition

        // binary jumping technique

        // find 2^ith connected parent.

        // then binary search on till kth parent if that value is having index higher then required value
        // binary connections towards right.

        vector<vector<int>> parent(n, vector<int>(21, -1));

        for(int i = n - 2; i >= 0; i --) {

            int start = i + 1, end = n - 1, poss_node = i;
            while(start <= end) {
                int mid = (start + end) / 2;
                if(node_with_values[mid][0] - node_with_values[i][0] <= maxDiff) {
                    poss_node = mid;
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }

            if(poss_node > i) {
                parent[i][0] = poss_node;
                for(int j = 1; j <= 19; j ++) {
                    if(parent[i][j - 1] >= 0) {
                        parent[i][j] = parent[parent[i][j - 1]][j - 1];
                    }
                }
            }
        }

        vector<int> ans;
        for(auto it: queries) {
            int v1 = it[0];
            int v2 = it[1];

            if(reverse_index[v1] > reverse_index[v2]) {
                swap(v1, v2);
            }

            if(v1 == v2) {
                ans.push_back(0);
                continue;
            }

            int s_r = reverse_index[v1];
            int e_r = reverse_index[v2];
            int start = 1, end = n - 1;
            int an = -1;
            while(start <= end) {
                int mid = (start + end) / 2;
                int parent_mid = findkthParent(s_r, mid, parent);
                if(parent_mid == -1) {
                    end = mid - 1;
                } else if(parent_mid >= e_r) {
                    an = mid;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            ans.push_back(an);
        }
        return ans;
    }
};