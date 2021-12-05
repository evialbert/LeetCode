class Solution {
    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        
        Engineer[] eng = new Engineer[n];
		for (int i = 0; i < n; i++) {
			eng[i] = new Engineer(speed[i], efficiency[i]);
		}
		Arrays.sort(eng);
		PriorityQueue<Engineer> pq = new PriorityQueue<Engineer>((a, b) -> a.speed - b.speed);

	    long max = 0;
		long sum = 0;

		for (int i = 0; i < n; i++) {
			pq.add(eng[i]);
			sum += eng[i].speed;
			if (pq.size() > k) {
				sum -= pq.poll().speed;
			}
			
			long tempPerformace = sum * (long) eng[i].eff;
			max = Math.max(max,tempPerformace);

		}

		 return (int) (max % 1000000007);
        
    }
    
    static class Engineer implements Comparable<Engineer> {
		int speed;
		int eff;

		Engineer(int speed, int eff) {
			this.speed = speed;
			this.eff = eff;
		}

		public int compareTo(Engineer e) {
			return e.eff - this.eff;

		}
	}
}