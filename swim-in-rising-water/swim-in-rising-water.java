class Solution {
    class Node {
        int x, y, time, key;
        Node(int x, int y, int time) {
            this.x = x; this.y = y; this.time = time; this.key = x*51 + y;
        }
    }
    public int swimInWater(int[][] grid) {
        HashSet<Integer> cache = new HashSet<>();
        PriorityQueue<Node> pq = new PriorityQueue<>((a,b) -> a.time - b.time);
        pq.add(new Node(0,0,grid[0][0]));
        while(!pq.isEmpty()) {
            Node top = pq.poll();
            if(cache.contains(top.key)) continue;
            cache.add(top.key);
            if(top.x == grid.length-1 && top.y == grid[0].length-1) return top.time;
            if(top.x > 0) pq.add(new Node(top.x-1, top.y, Math.max(top.time, grid[top.x-1][top.y])));
            if(top.x < grid.length-1) pq.add(new Node(top.x+1, top.y, Math.max(top.time, grid[top.x+1][top.y])));
            if(top.y > 0) pq.add(new Node(top.x, top.y-1, Math.max(top.time, grid[top.x][top.y-1])));
            if(top.y < grid[0].length-1) pq.add(new Node(top.x, top.y+1, Math.max(top.time, grid[top.x][top.y+1])));
        }
        return -1;
    }
}