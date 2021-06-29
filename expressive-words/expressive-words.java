class Solution {
    public int expressiveWords(String s, String[] words) {
        int res = 0;
        for(String word : words) {
            if(match(word, s)) {
                res++;
            }
        }
        
        return res;
    }
    
    private boolean match(String s, String t) {
        boolean extended = false;
        int i = 0, j = 0;
        while(i < s.length() && j < t.length()) {
            if(s.charAt(i) != t.charAt(j))  return false;
            int k = i+1, l = j+1;
            while(k < s.length() && s.charAt(k) == s.charAt(i)) {
                k++;
            }
            while(l < t.length() && t.charAt(l) == t.charAt(j)) {
                l++;
            }
            if(l-j > k - i && l-j >= 3) {
                extended = true;
            } else if(l-j != k-i) {
                return false;
            }
            i = k;
            j = l;
        }
        return extended && i == s.length() && j == t.length();
    }
}