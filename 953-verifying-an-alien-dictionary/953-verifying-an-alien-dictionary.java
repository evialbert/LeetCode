class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        Map<Character, Integer> mp = new HashMap<>();
        for(int i=0;i<order.length();i++){
          mp.put(order.charAt(i), i);
        }
      
        for(int i=0;i<words.length-1;i++){
          int k = Math.min(words[i].length(), words[i+1].length());
          for(int j=0;j<k;j++){
             if(mp.get(words[i].charAt(j)) < mp.get(words[i+1].charAt(j)))break;
                       
              else if(mp.get(words[i].charAt(j)) > mp.get(words[i+1].charAt(j)))return false;
              
              else if(j == k-1 && words[i].length() > words[i+1].length())return false;
                        
          }
      }
      return true;
        
        
    }
}