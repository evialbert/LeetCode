class Solution {
    public String addSpaces(String s, int[] spaces) {
         StringBuilder sb = new StringBuilder();
         int i = 0 ;
         int n = s.length();
         int idx = 0;
		 
       while(i < n && idx < spaces.length){
        //Add spaces when required
         if(spaces[idx] == i){
            sb.append(" ");
            idx++;
           }
           sb.append(s.charAt(i));
           i++;
        
       }
      //Work for additional string that we left with
       while(i < n){
         sb.append(s.charAt(i++));
       }
      
      return sb.toString();
    }
}