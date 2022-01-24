class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        if(arr.length == 0) return 0;
        
		// Sort the queue in ascending order of frequencies, so that least frequent element is always at the top
        PriorityQueue<Map.Entry<Integer, Integer>> minHeap
            = new PriorityQueue<>((a, b) -> a.getValue() - b.getValue());
        HashMap<Integer, Integer> frequencies = new HashMap<>();
        
		// Fill up the hashMap where key = array element and value = its frequency
        for(int a: arr) frequencies.put(a, frequencies.getOrDefault(a, 0) + 1);
        
		// Put the hashMap entries into the priority queue
        for(Map.Entry<Integer, Integer> entry: frequencies.entrySet()) minHeap.add(entry);
        
		// Remove elements from queue one by one
		// When we top elements, least frequent elements are removed, which will keep most frequent, i.e. least unique elements in the queue at the end
		// Reduce k by the frequency of removed element
		// E.g. if element '5' with frequency '2' is removed, k will be decreased by 2
        while(k > 0) {
            Map.Entry<Integer, Integer> entry = minHeap.poll();
            if(entry.getValue() > k) {
                entry.setValue(entry.getValue() - 1);
                minHeap.add(entry);
                k--;
            } else {
                k -= entry.getValue();
            }
        }
        
		// All the remaining elements in the heap are most frequent, i.e. least unique elements
        return minHeap.size();
    }
}