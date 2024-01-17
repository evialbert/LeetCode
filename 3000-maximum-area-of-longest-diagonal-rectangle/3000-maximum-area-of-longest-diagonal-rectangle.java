class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        PriorityQueue<int[]>pq=new PriorityQueue<>((a,b)->a[0]==b[0]?b[1]-a[1]:b[0]-a[0]);
        for(int d[]:dimensions)
        {
            pq.add(new int[]{d[0]*d[0]+d[1]*d[1],d[0]*d[1]});
        }
        return pq.peek()[1];
    }
}