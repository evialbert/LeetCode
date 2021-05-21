class Solution {
  static class Pair implements Comparable<Pair>{
    char c;
    int val;
    Pair(char c,int val){
      this.c=c;
      this.val=val;
    }
    
    public int compareTo(Pair o){
      return this.val-o.val;
    }
    
  }
    public String reorganizeString(String s) {
       PriorityQueue<Pair> maxheap=new PriorityQueue<>(Collections.reverseOrder());
       Map<Character,Integer> mp=new HashMap<>();
       for(char c:s.toCharArray()){
         
         mp.put(c,mp.getOrDefault(c,0)+1);
         
       }
       
      for(char key:mp.keySet()){
        maxheap.add(new Pair(key,mp.get(key)));
      }
       String res="";
       while(maxheap.size()>0){
         
         Pair rem=maxheap.poll();
		 //For first char
         if(res.length()==0){
         res=res+rem.c;
         int nv=rem.val-1;   //new value
         if(nv>0){
         maxheap.add(new Pair(rem.c,nv));
         }  
         }
		 //Current char should not be equals to our prev char
        else if(res.charAt(res.length()-1)!=rem.c){
         res=res+rem.c;
         int nv=rem.val-1;   //new value
         if(nv>0){
         maxheap.add(new Pair(rem.c,nv));
         }
         }
         else{
		 //if prev char is equals to our current char
           if(!maxheap.isEmpty()){
             Pair rem2=maxheap.poll();
            
             res=res+rem2.c;
             int nv=rem2.val-1;   //new value
            if(nv>0){
            maxheap.add(new Pair(rem2.c,nv));
            
         }
		  //Explicitly add the the prev char object as it not used .
             maxheap.add(rem);
           }
         }
       }
      //custom check 
      if(res.length()!=s.length()) return "";
      
      return res;
    }
}