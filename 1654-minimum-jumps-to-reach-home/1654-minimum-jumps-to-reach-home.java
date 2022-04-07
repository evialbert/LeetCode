class Solution {
	public int minimumJumps(int[] forbidden, int f, int b, int t) {
		int n=forbidden.length,minSteps=-1,deadEnd=t;
		Queue<int []> q=new PriorityQueue<>((e1,e2)->e1[1]-e2[1]);
		q.add(new int[]{0,0,0});
		Set<String> vis=new HashSet<>();
		for(int i=0;i<n;i++){
			vis.add(forbidden[i]+" 0");
			vis.add(forbidden[i]+" 1");
			deadEnd=Math.max(deadEnd,forbidden[i]);
		}
		deadEnd+=f+b;
		while(!q.isEmpty()){
			int x[]=q.poll();
			if(x[0]==t){
				minSteps=x[1];
				break;
			}
			if(x[0]+f<=deadEnd && vis.add((x[0]+f)+" 0"))	q.add(new int[]{x[0]+f,x[1]+1,0});
			if(x[2]!=1 && x[0]-b>0 && vis.add((x[0]-b)+" 1")){
				x[0]-=b;x[1]++;x[2]=1;
				q.add(x);
			}
		}
		return minSteps;
	}
}