class Solution {

    ArrayList<ArrayList<int[]>>adj;
    int limit;
    int n;
    
    public int minimumThreshold(int num, int[][] edges, int source, int target, int k) {

        adj=new ArrayList<>();
        limit=k;
        n=num;
        int max=Integer.MIN_VALUE;

        if(source==target){
            return 0;
        }

        for(int i=0;i<n;i++){
            adj.add(new ArrayList<>());
        }
        for(int[] e:edges){

            int u=e[0];
            int v=e[1];
            int w=e[2];

            adj.get(u).add(new int[]{v,w});
            adj.get(v).add(new int[]{u,w});

            max=Math.max(max,w);
        }
        int ans=-1;

        int l=0;
        int r=max;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(valid(source,target,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    public boolean valid(int src,int end,int mid){

        int[] dist=new int[n];
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[src]=0;

        PriorityQueue<int[]>pq=new PriorityQueue<>((a,b)->Integer.compare(a[1],b[1]));
        pq.offer(new int[]{src,0});

        while(!pq.isEmpty()){
            int[] curr=pq.poll();

            int currNode=curr[0];
            int currDist=curr[1];

            if(currDist>dist[currNode]){
                continue;
            }
            if(currNode==end && dist[currNode]<=limit){
                return true;
            }

            for(int[] neigh:adj.get(currNode)){

                int cost=neigh[1]>mid?1:0;

                if(currDist+cost<dist[neigh[0]]){
                    dist[neigh[0]]=currDist+cost;
                    pq.offer(new int[]{neigh[0],dist[neigh[0]]});
                }
            }
        }
        return dist[end]<=limit;
    }
}