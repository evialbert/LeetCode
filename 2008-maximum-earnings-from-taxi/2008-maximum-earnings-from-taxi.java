class Solution {
    public long maxTaxiEarnings(int n, int[][] rides) {
        Arrays.sort(rides,(a,b)->a[0]-b[0]);
        
        PriorityQueue<long[]>pq=new PriorityQueue<>((a,b)->Long.compare(a[0],b[0]));
        long maxf=0;
        
        for(int i=0;i<rides.length;i++){
            while(pq.size() > 0 && pq.peek()[0] <= rides[i][0])
                maxf=Math.max(maxf,pq.remove()[1]);
            
            pq.add(new long[]{rides[i][1],rides[i][1]-rides[i][0]+rides[i][2]+maxf});
        }
       long sum=0;
        
        while(pq.size() > 0)
            sum=Math.max(sum,pq.remove()[1]);
        
        return sum;
        
    }
}