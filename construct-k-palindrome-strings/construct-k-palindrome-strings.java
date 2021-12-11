class Solution {
   public boolean canConstruct(String s, int k) {
        int[] map = new int[26];
        for (int i = 0; i < s.length(); i++)
            map[s.charAt(i)-'a']++;
        int odd = 0;
        for (int i = 0; i < 26;i++)
            if (map[i]%2 == 1)
                odd++;
        
        return s.length() >= k && odd <= k;
    }
}