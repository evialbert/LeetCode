class Solution {
public:
    vector<int> findMedian(int n, vector<vector<int>>& edges,
                           vector<vector<int>>& queries) {
        int log2n = ceil(log2(n)) + 1;
        vector<vector<int>> binaryLifting(
            n, vector<int>(log2n, -1)); // parent only!
        vector<int> depthArr(n);
        vector<long long> cumSum(n); // Distance from root (0) to each node
        vector<int> result(queries.size());

        // Build adjList
        vector<unordered_map<int, int>> adjList(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adjList[u][v] = w;
            adjList[v][u] = w;
        }

        // DFS to fill depth, cumSum, and parent table
        dfs(-1, 0, adjList, binaryLifting, 0, depthArr, 0, cumSum);

        // Build full binary lifting table (parents only)
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < log2n; j++) {
                int p = binaryLifting[i][j - 1];
                if (p == -1) {
                    binaryLifting[i][j] = -1;
                } else {
                    binaryLifting[i][j] = binaryLifting[p][j - 1];
                }
            }
        }

        // For each query
        for (int q = 0; q < queries.size(); ++q) {
            int u = queries[q][0], v = queries[q][1];
            int lca = findLCA(u, v, binaryLifting, depthArr, log2n);
            long long totalPath = cumSum[u] + cumSum[v] - 2 * cumSum[lca];
            long long half = (totalPath + 1) / 2; // >= half
            long long beginlcaLegSum = cumSum[u] - cumSum[lca];

            // cout << " half " << half << endl;
            // cout << " left leg total " << beginlcaLegSum << endl;
            // lcatoEndLeg;
            if (beginlcaLegSum < half) {
                long long remainingCover = half - beginlcaLegSum; // exceeded number.
                int node = v;
                long long lcatoEndLen = cumSum[v] - cumSum[lca];
                long long lenToCover = lcatoEndLen - remainingCover;

                for (int k = log2n - 1; k >= 0; --k) {
                    int ancestor = binaryLifting[node][k];
                    if (ancestor == -1 || depthArr[ancestor] < depthArr[lca]) {
                        continue;
                    }
                    long long upwardDist = cumSum[v] - cumSum[ancestor];
                    // cout << " ancestor is " << ancestor << endl;
                    // cout << "upwardDist is " << upwardDist << endl;
                    // there could be an off by one error here
                    if (upwardDist <= lenToCover) {
                        node = ancestor;
                    }
                }

                // cout << " the node for the right leg search is " << node
                //      << endl;
                // After jumps, check if one more step passes threshold
                // if (node != lca && cumSum[v] - cumSum[node] < lenToCover) {
                //     node = binaryLifting[node][0];
                // }
                // cout << " the node for the right leg search is " << node
                //  << endl;
                result[q] = node;

            } else {
                // Walk from u toward lca, take largest jumps possible
                int node = u;
                for (int k = log2n - 1; k >= 0; --k) {
                    int ancestor = binaryLifting[node][k];
                    if (ancestor == -1 || depthArr[ancestor] < depthArr[lca])
                        continue;
                    long long upwardDist = cumSum[u] - cumSum[ancestor];
                    if (upwardDist < half) {
                        node = ancestor;
                    }
                }

                // cout << " the node for the left leg search is " << node << endl;
                // After jumps, check if one more step passes threshold
                if (node != lca && cumSum[u] - cumSum[node] < half) {
                    node = binaryLifting[node][0];
                }
                // cout << " the node for the left leg search is " << node << endl;
                result[q] = node;
            }
        }

        // for(int i = 0 ; i < n ; i++) {
        //     cout << "at i :: " << i << " cumsum is " << cumSum[i] << endl;
        // }
        return result;
    }

    int findLCA(int u, int v, const vector<vector<int>>& binaryLifting,
                const vector<int>& depthArr, int log2n) {
        if (depthArr[u] < depthArr[v])
            swap(u, v);
        // Bring u up to v's depth
        for (int k = log2n - 1; k >= 0; --k) {
            if (binaryLifting[u][k] != -1 &&
                depthArr[u] - (1 << k) >= depthArr[v]) {
                u = binaryLifting[u][k];
            }
        }
        if (u == v)
            return u;
        // Lift both up together
        for (int k = log2n - 1; k >= 0; --k) {
            if (binaryLifting[u][k] != -1 &&
                binaryLifting[u][k] != binaryLifting[v][k]) {
                u = binaryLifting[u][k];
                v = binaryLifting[v][k];
            }
        }
        return binaryLifting[u][0];
    }

    // DFS fills in parent, depth, cumSum
    void dfs(int parent, int node, vector<unordered_map<int, int>>& adjList,
             vector<vector<int>>& binaryLifting, int depth,
             vector<int>& depthArr, long long distFromRoot,
             vector<long long>& cumSum) {
        binaryLifting[node][0] = parent;
        depthArr[node] = depth;
        cumSum[node] = distFromRoot;
        for (const auto& [next, weight] : adjList[node]) {
            if (next == parent)
                continue;
            dfs(node, next, adjList, binaryLifting, depth + 1, depthArr,
                distFromRoot + weight, cumSum);
        }
    }
};