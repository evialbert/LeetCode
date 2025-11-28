class Solution {
    int count; // Global variable to keep track of the number of k-divisible components

    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        // Prepare adjacency list to represent the graph
        ArrayList[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        count = 0; // Initialize the count of k-divisible components to 0

        // Build the adjacency list from the edges
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].add(v); // Add v to u's adjacency list
            adj[v].add(u); // Add u to v's adjacency list (since the graph is undirected)
        }

        // Start DFS traversal from node 0 with -1 as the parent (no parent for the root)
        sol(0, -1, adj, values, k);

        // Return the total number of k-divisible components found
        return count;
    }

    // Helper method for DFS traversal
    private int sol(int curr, int prev, ArrayList<Integer>[] adj, int[] values, int k) {
        int sum = 0; // Initialize the sum of values for the current subtree

        // Iterate over all adjacent nodes of the current node
        for (int v : adj[curr]) {
            if (v == prev) continue; // Skip the parent node to avoid revisiting it
            sum += sol(v, curr, adj, values, k); // Recursive call to process the subtree rooted at v
        }

        sum += values[curr]; // Add the value of the current node to the sum

        sum = sum % k; // Reduce the sum modulo k

        // If the sum modulo k is 0, we found a k-divisible component
        if (sum == 0) {
            count++; // Increment the count of k-divisible components
        }

        // Return the sum of the subtree to the parent node
        return sum;
    }
}