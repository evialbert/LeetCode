class Solution {

  public boolean isAlienSorted(String[] words, String order) {

    if (words == null || words.length == 0 || order == null || order.length() == 0) {

      return false;

    }

    Map<Character, Integer> orderRule = new HashMap<>();

    for (int i = 0; i < order.length(); ++i) {

      char ch = order.charAt(i);

      orderRule.put(ch, i);

    }

    

    for (int i = 0; i < words.length - 1; ++i) {

      String s1 = words[i];

      String s2 = words[i + 1];

      int j = 0;

      while (j < s1.length() && j < s2.length() && s1.charAt(j) == s2.charAt(j)) {

        ++j;

      }

      if (j < s1.length() && j < s2.length()) {

        if (orderRule.get(s1.charAt(j)) > orderRule.get(s2.charAt(j))) {

          return false;

        }

      } else {

        if (j < s1.length() && j >= s2.length()) return false; // "abcdef" vs. "abc"

      }

    }

    return true;

  }

}