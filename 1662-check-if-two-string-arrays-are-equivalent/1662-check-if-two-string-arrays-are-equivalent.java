
  class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        String result1 = "";
        String result2 = "";
        
        for (int i = 0; i < word1.length; i++) {
            result1 = result1 + word1[i];
        }
        
        for (int i = 0; i < word2.length; i++) {
            result2 = result2 + word2[i];
        }
        
        return result1.equals(result2);
    }
}
