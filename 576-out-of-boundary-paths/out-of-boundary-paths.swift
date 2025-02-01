class Solution {
    func findPaths(_ m: Int, _ n: Int, _ maxMove: Int, _ startRow: Int, _ startColumn: Int) -> Int {
        var seen: [String: Int] = [:]

        func dfs(_ row: Int, _ column: Int, _ remainingMoves: Int) -> Int {
            if (remainingMoves < 0) { return 0 }
            if (row < 0 || column < 0 || row >= m || column >= n) { return 1 }
            let key = "\(row), \(column), \(remainingMoves)"
            if seen.keys.contains(key) { return seen[key] ?? 0 }
            let result = (
                dfs(row, column - 1, remainingMoves - 1) +
                dfs(row, column + 1, remainingMoves - 1) +
                dfs(row - 1, column, remainingMoves - 1) +
                dfs(row + 1, column, remainingMoves - 1)
            ) % (7 + Int(pow(10.0, 9.0)))
            seen[key] = result
            return result
        }
        return dfs(startRow, startColumn, maxMove) % (7 + Int(pow(10.0, 9.0)))
    }
}