class Solution {
    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        HashMap<Character,ArrayList<Integer>> mp=new HashMap<>();
        List<Integer> lst=new ArrayList<>();
        for(int i=0;i<26;i++){
          mp.put((char)(i+'a'),new ArrayList<>());
        }
      for(String word:words){
        int mask=0;
        for(char ch:word.toCharArray()){
          int bit=ch-'a';
          mask=mask | ((1<<bit));
            
        }
        HashSet<Character> hs=new HashSet<>();
        for(char ch:word.toCharArray()){
          if(!hs.contains(ch)){
          mp.get(ch).add(mask);
          }
          hs.add(ch);
        }
      }
      
      for(String puzzle:puzzles){
         int mask=0;
        for(char ch:puzzle.toCharArray()){
          int bit=ch-'a';
          mask=mask | ((1<<bit));
            
        }
        char fch=puzzle.charAt(0);
        ArrayList<Integer> wordstocheck=mp.get(fch);
        int count=0;
        for(int wmask:wordstocheck){
          if((wmask & mask)== wmask){
            count++;
          }
          
        }
        lst.add(count);
      }
      return lst;
    }
}