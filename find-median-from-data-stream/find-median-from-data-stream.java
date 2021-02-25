class MedianFinder {
    private PriorityQueue<Integer> minHeap;
    private PriorityQueue<Integer> maxHeap;
    /** initialize your data structure here. */
    public MedianFinder() {
        minHeap = new PriorityQueue<Integer>();
        maxHeap = new PriorityQueue<Integer>(Collections.reverseOrder());        
    }
    
    public void addNum(int num) {
        maxHeap.add(num);
        minHeap.add(maxHeap.poll());
        if(maxHeap.size() < minHeap.size()) {
            maxHeap.add(minHeap.poll());
        }
            
    }
    
    public double findMedian() {
        return maxHeap.size() > minHeap.size() ? maxHeap.peek(): (maxHeap.peek() + minHeap.peek())/2.0;
    }
}