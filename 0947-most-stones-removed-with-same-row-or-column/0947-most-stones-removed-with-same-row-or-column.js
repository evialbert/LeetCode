/**
 * @param {number[][]} stones
 * @return {number}
 */
var removeStones = function(stones) {
    const parent = {};

    // Find function with path compression
    const find = (x) => {
        if (parent[x] === undefined) {
            parent[x] = x;
        }
        if (parent[x] !== x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    };

    // Union function
    const union = (x, y) => {
        const rootX = find(x);
        const rootY = find(y);
        if (rootX !== rootY) {
            parent[rootX] = rootY;
        }
    };

    // Union all stones that share the same row or column
    for (const [x, y] of stones) {
        union(x, ~y);  // Use a unique key for columns (e.g., ~y)
    }

    const uniqueRoots = new Set();
    for (const [x, y] of stones) {
        uniqueRoots.add(find(x));
    }

    return stones.length - uniqueRoots.size;
};
