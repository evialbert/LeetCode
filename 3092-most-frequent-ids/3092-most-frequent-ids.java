class Solution {
    public long[] mostFrequentIDs(int[] nums, int[] freq) {
        int n = nums.length;
        long[] ans = new long[n];
        PriorityQueue<Pair<Integer, Long>> heap = new PriorityQueue<Pair<Integer, Long>>((a,b) -> {
            if(b.getValue() >= a.getValue())
                return 1;
            return -1;
        });
        Map<Integer, Long> map = new HashMap<>();
        
        for(int i=0; i<n; i++){
            int ID = nums[i];
            int change = freq[i];
            map.put(ID, map.getOrDefault(ID, 0l) + change);
            heap.add(new Pair(ID, map.get(ID)));
            while(map.get(heap.peek().getKey()) != heap.peek().getValue())
                heap.poll();
            ans[i] = heap.peek().getValue();
        }
        return ans;
    }
}