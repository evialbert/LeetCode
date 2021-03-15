class Solution {
    // Time: O(b + s) , where b - big str, s - small str
    // Space: O(2*26 + b) , space for saving counters 
    // and b spase - at most if anagrams will be found at each index 
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> result = new ArrayList<Integer>();
        if (s == null || s.length() < p.length()) return result;
        
        // arrays sizes
        int pSize = p.length();
        int sSize = s.length();
        // counting chars in small string
        int[] small = new int[26];
        for (int i = 0; i < pSize; i++) {
            small[p.charAt(i) - 'a']++;
        }

        // dynamic counting in big string using one iteration
        int[] big = new int[26];

        for (int i = 0; i < sSize; i++) {
            // increment count on char in range
            big[s.charAt(i) - 'a']++;
            // reduce counter at char out of range
            int l = i - pSize;
            if (l >= 0) {
                big[s.charAt(l) - 'a']--;
            }
            // if arrays have same counts - new anagram found
            if (Arrays.equals(big, small)) {
                result.add(l + 1);
            }
        }
        
        return result;
    }
    
    private void print(String s, int[] array) {
        System.out.println("");
        System.out.print(s + ": ");
        for (int i : array) {
            System.out.print(i + " ");
        }
    }
    
}