class Solution {
   public static int[] kthSmallestPrimeFraction(int[] A, int K) {
		PriorityQueue<int[]> minHeap = new PriorityQueue<int[]>(new Comparator<int[]>() {
			public int compare(int[] i1, int[] i2) {
				return Integer.compare(A[i1[0]] * A[i2[1]], A[i1[1]] * A[i2[0]]);
			}
		});

		for (int i = 0; i < A.length - 1; i++)
			minHeap.offer(new int[] { i, A.length - 1 });

		for (int i = 0; i < K - 1; i++) {
			int[] curMin = minHeap.poll();
			if (curMin[1] - 1 > curMin[0])
				minHeap.offer(new int[] { curMin[0], curMin[1] - 1 });
		}

		int[] ret = minHeap.poll();
		return new int[] { A[ret[0]], A[ret[1]] };
	}
}