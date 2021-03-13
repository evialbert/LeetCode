class Solution {
   public int countBattleships(char[][] board) {
		int N = board.length;
		int M = board[0].length;

		boolean[][] visited = new boolean[N][M];

		int cnt = 0;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (board[i][j] == 'X' && !visited[i][j])
				{
					// down
					dfs(board, N, M, i, j, visited, 0);
					// right
					dfs(board, N, M, i, j, visited, 1);

					cnt++;
				}
			}
		}

		return cnt;
	}

	private void dfs(char[][] board, int N, int M, int i, int j, boolean[][] visited, int dir)
	{
		if (board[i][j] != 'X') return;
		visited[i][j] = true;

		if (dir == 0) {
			if (i + 1 < N && !visited[i+1][j])
				dfs(board, N, M, i + 1, j, visited, dir);


		} else {
			if (j + 1 < M && !visited[i][j+1]) {
				dfs(board, N, M, i, j +1, visited, dir);
			}
		}
	}
}