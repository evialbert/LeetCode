class Solution {
    public int minStoneSum(int[] piles, int k) {
        // int[] = {idx, num}
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((x, y) -> y[1] - x[1]);
        
        for(int i = 0; i < piles.length; i++) {
            maxHeap.add(new int[]{i, piles[i]});
        }
        
        while(!maxHeap.isEmpty() && k-- > 0) {
            int[] entry = maxHeap.poll();
            int remove = entry[1] / 2;
            piles[entry[0]] -= remove;
            maxHeap.add(new int[]{entry[0], piles[entry[0]]});
        }
        
        int sum = 0;
        
        for(int n : piles) sum += n;
        
        return sum;
    }
}