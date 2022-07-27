class Solution {
    
   private int dijkstra(int[][] roads,int n){
    long mod=(int)1e9+7;
	//PriorityQueue is used for sorting by time
    Queue<long[]> pq = new PriorityQueue<>((l, r) -> Long.compare(l[1], r[1]));
    //Number of ways to reach a vertex from 0 in minimum time
	long[] ways=new long[n];
	//Distance array to store the minimum time taken to reach a vertex
    long[] dist=new long[n];
	//Filling dist array with infinite distance.
    Arrays.fill(dist,(long)1e18);
    dist[0]=0;
	//Number of ways to reach 0 is 1.
    ways[0]=1;
	//We have to form graph roads array.
    ArrayList<long[]>[] graph=new ArrayList[n];
    for(int i=0;i<graph.length;i++) graph[i]=new ArrayList<>();
    for(int[] road:roads){
        graph[road[0]].add(new long[]{road[1],road[2]});
        graph[road[1]].add(new long[]{road[0],road[2]});
    }
    pq.add(new long[]{0,0});
	//Normal Dijkstra bfs is implemented.
	while(pq.size()>0){
        long[] ele=pq.remove();
        long dis=ele[1];
		//Node value we are on(Parent Node).
        long node=ele[0];
        for(long[] e:graph[(int)node]){
		//Adjancent Node weight from parent.
            long wt=e[1];
		//Adjacent Node to parent
            long adjNode=e[0];
			//If the wt+dis (i.e time here) is less than already time taken then will update dist[(int)adjNode] and number of ways will be equal to ways[(int)node]
            if(wt+dis<dist[(int)adjNode]){
                dist[(int)adjNode]=wt+dis;
                ways[(int)adjNode]=ways[(int)node];
                pq.add(new long[]{adjNode,dist[(int)adjNode]});
            }
			//if wt+dis (i.e time here) is equal to already taken time then we will add it in ways array.
            else if(wt+dis==dist[(int)adjNode]){
                ways[(int)adjNode]=(ways[(int)node]+ways[(int)adjNode])%mod;
            }
        }
    }
     return (int)ways[n-1];
}

public int countPaths(int n, int[][] roads) {
    return dijkstra(roads,n);        
}
}