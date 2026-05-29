class Solution {
    struct Node {
        int cost;
        int L;
        int R;
        bool dead;
    };

public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n / 2) return -1;
        if (k == 0) return 0;

        vector<Node> nodes(n);
        vector<pair<int, int>> initial_heap(n);

        for (int i = 0; i < n; ++i) {
            int left_idx = (i == 0) ? n - 1 : i - 1;
            int right_idx = (i == n - 1) ? 0 : i + 1;
            
            int target = max(nums[left_idx], nums[right_idx]) + 1;
            int cost = max(0, target - nums[i]);
            
            nodes[i] = {cost, left_idx, right_idx, false};
            initial_heap[i] = {cost, i};
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq(
            initial_heap.begin(), initial_heap.end()
        );

        int ans = 0;

        while (k > 0 && !pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (nodes[u].dead) continue;

            ans += cost;
            k--;

            int l = nodes[u].L;
            int r = nodes[u].R;

            nodes[l].dead = true;
            nodes[r].dead = true;

            nodes[u].cost = nodes[l].cost + nodes[r].cost - nodes[u].cost;
            pq.push({nodes[u].cost, u});

            nodes[u].L = nodes[l].L;
            nodes[u].R = nodes[r].R;
            
            nodes[nodes[u].L].R = u;
            nodes[nodes[u].R].L = u;
        }

        return ans;
    }
};