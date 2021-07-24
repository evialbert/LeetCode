class RLEIterator {
    ArrayDeque<Integer> q;
    public RLEIterator(int[] encoding) {
        q = new ArrayDeque<>();
        for(int  val : encoding){
           q.addLast(val);
        }
    }
    
    public int next(int n) {
      int le = -1;
      while(n > 0 && q.size() >= 2){
         int freq = q.removeFirst();
         int num  = q.removeFirst();
         if(freq >= n){
            freq = freq - n;
            
          if(freq !=0 ){ 
            q.addFirst(num);
            q.addFirst(freq);
          }
           return num;
         }
         else{
           n = n - freq;
        }
        le = num;
      }
      if(n != 0) return -1;
      
      return le;
    }
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(encoding);
 * int param_1 = obj.next(n);
 */