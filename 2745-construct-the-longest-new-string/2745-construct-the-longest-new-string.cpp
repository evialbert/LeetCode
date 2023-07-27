class Solution {
    int memo[51][51][51][3];
    int dfs(int x, int y, int z, int last = 2) {
        // base case: already been here
        if (memo[x][y][z][last] != -1) return memo[x][y][z][last];
        // general case
        return memo[x][y][z][last] = max(
            max(
                // adding "AA", if possible
                last && x ? 2 + dfs(x - 1, y, z, 0) : 0,
                // adding "AB", if possible
                last && z ? 2 + dfs(x, y, z - 1, 1) : 0
            ),
            // adding "BB", if possible
            last != 1 && y ? 2 + dfs(x, y - 1, z, 1) : 0
        );
    }
public:
    int longestString(int x, int y, int z) {
        for (int cx = 0; cx <= x; cx++) {
            auto memox = memo[cx];
            for (int cy = 0; cy <= y; cy++) {
                auto memoy = memox[cy];
                for (int cz = 0; cz <= z; cz++) {
                    auto memoz = memoy[cz];
                    for (int l = 0; l < 3; l++) {
                        memoz[l] = -1;
                    }
                }
            }
        }
        return dfs(x, y, z);
    }
};