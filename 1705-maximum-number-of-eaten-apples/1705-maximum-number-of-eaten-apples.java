class Solution {
    public int eatenApples(int[] apples, int[] days) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> a[1] - b[1]);
        
        int total = 0;
         
        for(int i=0; i<apples.length; i++){
            if(apples[i] != 0 && days[i] != 0)
                pq.offer(new int[]{apples[i], i+days[i]});
            
            while(!pq.isEmpty()){
                int apple = pq.peek()[0];
                int expiration_day = pq.poll()[1];
                
                if(expiration_day > i){
                    total++;
                    
                    apple--;
                
                    if(apple > 0 && expiration_day > i)
                        pq.offer(new int[]{apple, expiration_day});
                    
                    break;
                }
            }
        }
        
        int day = days.length;
        
        while(!pq.isEmpty()){          
            int apple = pq.peek()[0];
            int expiration_day = pq.poll()[1];
            
            if(expiration_day > day){
                total++;
                
                apple--;
            
                if(apple > 0 && expiration_day > day)
                    pq.offer(new int[]{apple, expiration_day});

                day++;
            }
        }
        
        return total;
    }
}