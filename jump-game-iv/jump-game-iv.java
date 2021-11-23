class Solution {

	static class Pair{
		int index;
		int jumps;
		public Pair(int index, int jumps){
			this.index = index;
			this.jumps = jumps;
		}
	}

	public int minJumps(int[] arr) {
		if(arr == null || arr.length < 2){
			return 0;
		}

		Map<Integer, LinkedList<Integer>> occurMap = new HashMap<>();
		for(int i = 0; i < arr.length; i++){
			occurMap.putIfAbsent(arr[i], new LinkedList<>());
			occurMap.get(arr[i]).add(i);
		}

		Queue<Pair> queue = new LinkedList<>();
		queue.offer(new Pair(0, 0));
		boolean[] visited = new boolean[arr.length];
		visited[0] = true;

		while(!queue.isEmpty()){
			int queueSize = queue.size();
			for(int i = 0; i < queueSize; i++){
				Pair currPair = queue.poll();
				if(currPair.index == arr.length - 1){
					return currPair.jumps;
				}
				int value = arr[currPair.index];
				LinkedList<Integer> neighboursPos = occurMap.get(value);
				neighboursPos.add(currPair.index - 1);
				neighboursPos.add(currPair.index + 1);
				while(neighboursPos.size() > 0){
					int currPos = neighboursPos.poll();
					if(currPos >= 0 && currPos < arr.length && !visited[currPos]){
						queue.offer(new Pair(currPos, currPair.jumps + 1));
						visited[currPos] = true;
					}
				}
			}

		}

		return 0;
	}
}