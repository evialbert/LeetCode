class Solution {
	public int[] loudAndRich(int[][] richer, int[] quiet) {
		int n=quiet.length,res[]=new int[n];
		Map<Integer,Set<Integer>> m=new HashMap<>();
		for(int i=0;i<richer.length;i++){
			int x=richer[i][0],y=richer[i][1];
			m.putIfAbsent(y,new HashSet<>());
			m.get(y).add(x);
		}
		Arrays.fill(res,-1);
		for(int i=0;i<n;i++)  if(res[i]==-1) get_ans(m,quiet,i,res);
		return res;
	}
	private int get_ans(Map<Integer,Set<Integer>> m,int []quiet,int st,int []res){
		if(m.containsKey(st)){
			if(res[st]==-1){
				res[st]=st;
				for(int i:m.get(st)){
					if(res[i]==-1){
						int ind=get_ans(m,quiet,i,res);
						if(quiet[res[st]]>quiet[ind])	res[st]=ind;
					}
					else{
						if(quiet[res[st]]>quiet[res[i]])	res[st]=res[i];
					}
				}
			}
		}
		else res[st]=st;
		return res[st];
	}
}