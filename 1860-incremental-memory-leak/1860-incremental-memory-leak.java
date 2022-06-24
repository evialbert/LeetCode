class Solution {
    public int[] memLeak(int memory1, int memory2) {
        PriorityQueue<Wrapper> maxHeap = new PriorityQueue<Wrapper>((a, b) -> {
            return a.mem == b.mem ? a.seq - b.seq : b.mem - a.mem;
        });
           
        maxHeap.offer(new Wrapper(memory1, 0));
        maxHeap.offer(new Wrapper(memory2, 1));
        int counter = 1;
        int [] result = new int[3];
        
        while(maxHeap.size () > 1) {
            if(maxHeap.peek().mem < counter) {
                break;
            }
            Wrapper wrap = maxHeap.poll();
            maxHeap.offer(new Wrapper(wrap.mem - counter, wrap.seq));
            counter++;
        }
        
        Wrapper first = maxHeap.poll(), second = maxHeap.poll();
        return (first.seq < second.seq) ? 
            new int[]{counter, first.mem, second.mem} : new int[]{counter, second.mem, first.mem};
    }
    
    private class Wrapper {
        int mem;
        int seq;
        
        Wrapper(int mem, int seq) {
            this.mem = mem;
            this.seq = seq;
        }
    }
}