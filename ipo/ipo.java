class Solution {
    
    // Time Complexity: nlogn(sorting) + nlogn(inserting n elements to heap in worst case) + klogn(removal of k elements from heap) = NlogN
    // Space: O(n) for heap.
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        if (profits == null || profits.length == 0) return w;
        
        int n = profits.length;
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; i++) {
            arr[i][0] = profits[i];
            arr[i][1] = capital[i];
        }
        
        // Sort by capital
        Arrays.sort(arr, (a, b) -> a[1] - b[1]);
        
        // Max heap of profits
        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>((a1,b1) -> Integer.compare(b1, a1));     
        
        for (int i = 0; i < n && k != 0 && w >= 0; k--) {
            if (arr[i][1] > w) break;
            
            // Pick projects whose capital <= w and add profit to max heap.
            while (i < n && arr[i][1] <= w) {
                maxHeap.add(arr[i][0]);
                i++;
            }
              
			// Get maximum profit till now and remove it from heap
            w += maxHeap.remove();
        }
        
        // Add projects which can be completed
        while (k-- != 0 && !maxHeap.isEmpty()) {
            w += maxHeap.remove();
        }
        
        return w;
    }
}