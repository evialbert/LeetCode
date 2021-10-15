class Solution {
    int par[];
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
       par = new int[s.length()];
       for(int i = 0; i < s.length();i++){
          par[i] = i;
       }
      
      for(List<Integer> pair : pairs){
        //Do union for the given pairs
           int x = (pair.get(0)) ;
           int y = (pair.get(1)) ;
           union(x,y);
        
      }
      Map<Integer,PriorityQueue<Character>> mp = new HashMap<>();
      
      for(int i = 0; i < s.length(); i++){
          int leader = find(i);
        //With respect to leader of every character maintain a pq(as we want to make smallest string)
          mp.putIfAbsent(leader,new PriorityQueue<>());
          mp.get(leader).add(s.charAt(i));
      }
     
      StringBuilder sb = new StringBuilder();
      for(int i = 0 ; i < s.length() ; i++){
          int leader = find(i);
        //Append the lowest character wrt to each char's leader
          char c = mp.get(leader).poll();
          sb.append(c);
      }
       
        return sb.toString();
    }
    void union(int x,int y){
      int lx = find(x);
      int ly = find(y);
      
      if(lx != ly){
        par[lx] = ly;
      }
    }
    int find(int x){
        if(par[x] == x){
           return x;
        }
      int temp = find(par[x]);
      par[x] = temp;
      return temp;
    }
    
}