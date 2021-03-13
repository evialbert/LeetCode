class Solution {
  // O(m*n)
// Depth First Search
public List<List<Integer>> pacificAtlantic(int[][] matrix) {

	List<List<Integer>> res = new ArrayList<List<Integer>>();

	if (matrix.length == 0)
		return res;

	int m = matrix.length, n = matrix[0].length;

	boolean[][] pacific = new boolean[m][n];
	boolean[][] atlantic = new boolean[m][n];

	for (int i = 0; i < m; i++) {
		dfs(i, 0, matrix, pacific, Integer.MIN_VALUE, m, n);
		dfs(i, n - 1, matrix, atlantic, Integer.MIN_VALUE, m, n);
	}

	for (int i = 0; i < n; i++) {
		dfs(0, i, matrix, pacific, Integer.MIN_VALUE, m, n);
		dfs(m - 1, i, matrix, atlantic, Integer.MIN_VALUE, m, n);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (pacific[i][j] && atlantic[i][j])
				res.add(new ArrayList<Integer>(Arrays.asList(i, j)));
		}
	}

	return res;
}

// O(m*n)
public void dfs(int x, int y, int[][] matrix, boolean[][] visited, int last, int m, int n) {

	visited[x][y] = true;
	int val = matrix[x][y];

	if (x - 1 >= 0 && !visited[x - 1][y] && matrix[x - 1][y] >= val)
		dfs(x - 1, y, matrix, visited, val, m, n);

	if (x + 1 < m && !visited[x + 1][y] && matrix[x + 1][y] >= val)
		dfs(x + 1, y, matrix, visited, val, m, n);

	if (y - 1 >= 0 && !visited[x][y - 1] && matrix[x][y - 1] >= val)
		dfs(x, y - 1, matrix, visited, val, m, n);

	if (y + 1 < n && !visited[x][y + 1] && matrix[x][y + 1] >= val)
		dfs(x, y + 1, matrix, visited, val, m, n);

}
}
