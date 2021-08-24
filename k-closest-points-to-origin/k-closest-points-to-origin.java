class Solution {
    
    public class Point {
        public int x;
        public int y;
        public int d;
        
        Point(int x, int y, int d) {
            this.d = d;
            this.x = x;
            this.y = y;
        }
        
        public String toString(){
            return this.x + "," + this.y + "->" + this.d;
        }
    }
    
    public class SortByDifference implements Comparator<Point> {
        // Used for sorting in ascending order of
        // roll number
        public int compare(Point a, Point b)
        {
            return -(a.d - b.d);
        }
    }
    
    public int[][] kClosest(int[][] points, int k) {
        //Your code here
        PriorityQueue<Point> maxHeap = new PriorityQueue<>(new SortByDifference());
        int n = points.length;
        
        for(int i=0; i<n; i++) {
            int x = points[i][0];
            int y =points[i][1];
            maxHeap.add(new Point(x, y, (x*x) + (y*y)));
            
            if(maxHeap.size() > k) {
                maxHeap.poll();
            }
            //System.out.println(maxHeap);
        }
        n = maxHeap.size();
        int result[][] = new int[n][2];
        for(int i=n-1; i>=0; i--) {
            Point p = maxHeap.poll();
            result[i][0] = p.x;
            result[i][1] = p.y;
        }
        
        return result;
    }
}