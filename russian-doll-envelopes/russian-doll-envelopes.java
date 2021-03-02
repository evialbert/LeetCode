class Solution {
    public static int maxEnvelopes(int[][] envelopes) {
        if(envelopes == null || envelopes.length == 0 || envelopes[0] == null || envelopes[0].length != 2)
        return 0;
        
		ArrayList<Pair> al = new ArrayList();
		for(int i = 0;i<envelopes.length;i++){
			al.add(new Pair(envelopes[i][0],envelopes[i][1]));	
		}
		al.sort((p1,p2)->p1.x-p2.x+p1.y-p2.y);
		int[] dp = new int[envelopes.length];
		int omax = 1;
		Arrays.fill(dp,1);
		for(int i = 1;i<dp.length;i++){
			int c = 0;
			for(int j = 0;j<i;j++){
				if(al.get(j).compareTo(al.get(i))==1){
					c = Math.max(c, dp[j]);
				}
			}
			dp[i] = c+1;
			omax = Math.max(omax, dp[i]);
		}
		return omax;
		
		
    }

	public static class Pair implements Comparable<Pair> {
		int x;
		int y;

		Pair(int a, int b) {
			x = a;
			y = b;
		}
		@Override
		public int compareTo(Pair p1) {
			if (p1.x > this.x && p1.y > this.y) {
				return 1;
			}
			return 0;
		}
		
	}
}
