class Solution {
    public int scheduleCourse(int[][] courses) {
        int time = 0;
        Arrays.sort(courses, (a, b) -> a[1] - b[1]);
        Queue<Integer> pq = new PriorityQueue<>((a, b) -> b - a); //max heap
        
        for (int[] course : courses) {
            pq.offer(course[0]);
            
            time += course[0];
            
            if (time > course[1]) time -= pq.poll();
        }
        
        return pq.size();
    }
}