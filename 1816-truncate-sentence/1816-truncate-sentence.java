class Solution {
      public String truncateSentence(String s, int k) {
        String[] words = s.split(" ");
        StringBuilder toReturn = new StringBuilder();
        for(int i = 0; i < k; i++) {
            toReturn.append(words[i]);
            if(i != k - 1) toReturn.append(" ");
        }
        
        return toReturn.toString();
    }
}