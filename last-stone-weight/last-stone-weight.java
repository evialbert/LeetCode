class Solution {
      public int lastStoneWeight(int[] stones) {
          if(stones == null || stones.length == 0){
              return 0;
          }
          
          PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
          for(int stone : stones){
              maxHeap.add(stone);
         }
         
         while(maxHeap.size() > 1){
             int x = maxHeap.poll();
             int y = maxHeap.poll();
             int diff = x-y;
             if(diff > 0){
                 maxHeap.add(diff);
             }
         }
        
         return maxHeap.isEmpty() ? 0 : maxHeap.peek();
     }
 }