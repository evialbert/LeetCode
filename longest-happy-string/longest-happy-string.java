class Solution {
	public String longestDiverseString(int a, int b, int c) {
		int freq[]=new int[3];
		freq[0]=a;freq[1]=b;freq[2]=c;
		Queue<Integer> q=new PriorityQueue<>((e1,e2)->freq[e2]-freq[e1]);
		if(a!=0)    q.add(0);
		if(b!=0)    q.add(1);
		if(c!=0)    q.add(2);
		StringBuilder sb=new StringBuilder();
		while(!q.isEmpty()){
			int x=q.poll();
			if(sb.length()>1 && sb.charAt(sb.length()-1)-97==x && sb.charAt(sb.length()-2)-97==x){
				if(q.isEmpty()) break;
				int t=q.poll();
				q.add(x);
				x=t;
			}
			sb.append((char)(x+97));
			if(--freq[x]!=0)    q.add(x);
		}
		return sb.toString();
	}
}