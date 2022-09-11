class Solution {
    public int countWords(String[] words1, String[] words2) {
    int result = 0;
    Map<String, Integer> wordCountInfo = new HashMap<>();
    Map<String, Integer> tickWords = new HashMap<>();
    for (int i = 0; i < words1.length; i++) {
      String word = words1[i];
      if (tickWords.containsKey(word)) {
        continue;
      }
      if (!wordCountInfo.containsKey(word)) {
        wordCountInfo.put(word, 0);
      } else {
        tickWords.put(word, 1);
        wordCountInfo.remove(word);
      }
    }
    for (int i = 0; i < words2.length; i++) {
      String word = words2[i];
      if (wordCountInfo.containsKey(word)) {
        Integer count = wordCountInfo.get(word);
        count++;
        wordCountInfo.put(word, count);
        if (count > 1) {
          result--;
          wordCountInfo.remove(word);
        } else {
          result++;
        }
      }
    }
    return result;
  }
}