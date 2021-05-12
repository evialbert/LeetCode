class Solution {
    public int[][] outerTrees(int[][] pois) {
        if (pois.length == 1) {
            return new int[][]{pois[0]};
        }
        Point[] points = new Point[pois.length];
        for (int i = 0; i < pois.length; ++i) {
            points[i] = new Point(pois[i][0], pois[i][1]);
        }
        Arrays.sort(points, (a, b) -> a.x == b.x ? a.y - b.y : a.x - b.x);
        int n = points.length;
        Stack<Point> boarder = new Stack<>();
        Set<Point> res = new HashSet<>();
        boarder.push(points[0]);
        boarder.push(points[1]);
        for (int i = 2; i < n; ++i) {
            Point top = boarder.pop();
            while (!boarder.isEmpty() && !isClock(boarder.peek(), top, points[i])) {
                top = boarder.pop();
            }
            boarder.push(top);
            boarder.push(points[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            Point top = boarder.pop();
            while (!boarder.isEmpty() && !isClock(boarder.peek(), top, points[i])) {
                top = boarder.pop();
            }
            boarder.push(top);
            boarder.push(points[i]);
        }
        for (Point p : boarder) {
            res.add(p);
        }
        int[][] ans = new int[res.size()][2];
        int i = 0;
        for (Point p : res) {
            ans[i][0] = p.x;
            ans[i++][1] = p.y;
        }
        return ans;
    }
    
    private boolean isClock(Point ori, Point p1, Point p2) {
        return (p1.x - ori.x) * (p2.y - ori.y) <= (p2.x - ori.x) * (p1.y - ori.y);
    }
    
    private class Point{
        int x;
        int y;
        
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}