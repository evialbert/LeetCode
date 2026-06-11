function assignEdgeWeights(edges: number[][]): number {
    const MOD = 1000000007n;
    const n = edges.length + 1;

    // 1. Build the adjacency list for the tree
    const graph: number[][] = Array.from({ length: n + 1 }, () => []);

    for (const [u, v] of edges) {
        graph[u].push(v);
        graph[v].push(u);
    }

    // 2. DFS to calculate the maximum depth from a given node
    const dfs = (node: number, prev: number): number => {
        let dist = 0;
        for (const c of graph[node]) {
            // Prevent traversing back to the parent node
            if (c !== prev) {
                dist = Math.max(dist, dfs(c, node) + 1);
            }
        }
        return dist;
    };

    // 3. Find the max depth starting from root node 1
    const d = dfs(1, 0);
    
    // Edge case: no edges
    if (d === 0) return 0;

    // 4. Binary Exponentiation: Calculate (2^(d-1)) % MOD
    let base = 2n;
    let exp = BigInt(d - 1);
    let result = 1n;

    while (exp > 0n) {
        // If exponent is odd, multiply base with result
        if (exp % 2n === 1n) {
            result = (result * base) % MOD;
        }
        // Square the base
        base = (base * base) % MOD;
        // Halve the exponent
        exp = exp / 2n;
    }

    // Convert BigInt back to standard Number for the return type
    return Number(result);
};