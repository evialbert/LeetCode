class Solution {
  public boolean canConvertString(String s, String t, int k){
        if(s.length()!=t.length()) return false;
        Map<Integer,Integer> map= new HashMap<>();
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)==t.charAt(i)) continue;
            int moves= 0;
            if(t.charAt(i)>s.charAt(i)) moves= t.charAt(i)-s.charAt(i);
            else{
                moves= 'z'-s.charAt(i)+t.charAt(i)-'a'+1;
            }
            if(map.containsKey(moves)){
                int less26= moves;
                moves= map.get(moves)+26;
                map.replace(less26,moves);
            }else{
                map.put(moves,moves);
            } 
            if(moves>k) return false;
        }
        return true;
    }
}