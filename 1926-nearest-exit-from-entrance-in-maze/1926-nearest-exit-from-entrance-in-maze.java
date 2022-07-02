class Solution {

	private int[][] dirs = new int[][]{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};      // Directions

	public int nearestExit(char[][] maze, int[] entrance) {
		int n = maze.length,m = maze[0].length;
		if(n==0 || m==0) return -1;                  // Base Case
		int x = entrance[0],y = entrance[1];
		
		// BFS
		int count = 0;
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[]{x,y});
		maze[x][y] = '+';

		while(!q.isEmpty()){
			count++;
			int size = q.size();

			while(size-- > 0){
				int[] cell = q.poll();
				int i = cell[0],j = cell[1];
				for(int[] dir : dirs){                                      // Traverse Each 4 Directions
					int a = i + dir[0];
					int b = j + dir[1];
					if(isInValid(a,b,n,m) || maze[a][b]!='.') continue;   // Invalid Cases
					if(a==0 || b==0 || a==n-1 || b==m-1) return count;   // If we found any exits then return count
					q.add(new int[]{a,b});                               // Else adding that cell to queue
					maze[a][b] = '+';
				}
			}
		}
		return -1;
	}

	boolean isInValid(int i,int j,int n,int m){
		return i<0||j<0||i>=n||j>=m;
	}

}