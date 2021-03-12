class Solution {
	class point{
		int x;
		int y;
		int h;
		public point(int x, int y, int h){
			this.x = x;
			this.y = y;
			this.h = h;
		}
	}
	public int trapRainWater(int[][] heightMap) {
		//corner case 
		if(heightMap == null || heightMap.length == 0 || heightMap[0].length == 0) return 0;

		PriorityQueue<point> heap = new PriorityQueue<>((a,b)-> a.h - b.h);

		int r = heightMap.length;
		int c = heightMap[0].length;
		
		boolean visited[][] = new boolean[r][c]; // to mark that points are visited;
		//process each first row and last row
		for(int i = 0; i < r; i++){
			heap.offer(new point(i, 0, heightMap[i][0]));
			heap.offer(new point(i, c-1, heightMap[i][c-1]));
			visited[i][0] = true;
			visited[i][c-1] = true;
		}

		//process each first column and last column
		for(int i = 0; i < c; i++){
			heap.offer(new point(0, i, heightMap[0][i]));
			heap.offer(new point(r-1,i, heightMap[r-1][i]));
			visited[0][i] = true;
			visited[r-1][i] = true;
		}

		int res = 0;

		int[][] direc = {{0, 1},{0, -1},{1, 0},{-1, 0}};
		while(!heap.isEmpty()){
			point start = heap.poll();
			for(int[] d: direc){
				int nx = start.x + d[0];
				int ny = start.y + d[1];

				if(nx > 0 && nx < r && ny >0 && ny < c && visited[nx][ny] != true){
					res += Math.max(0, start.h - heightMap[nx][ny]);
					heap.offer(new point(nx, ny, Math.max(start.h, heightMap[nx][ny])));
					visited[nx][ny] = true;
				}
			}

		}
		return res;
	}
}