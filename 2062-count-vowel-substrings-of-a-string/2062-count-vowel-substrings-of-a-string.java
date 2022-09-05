class Solution {
    public int countVowelSubstrings(String word) {
        int count = 0;
        int[] last = new int[5];
        Arrays.fill(last, -1);
        int start = -1;
        boolean formed = false;
        for (int pos = 0; pos < word.length(); pos++) {
            char c = word.charAt(pos);
            int idx = index(c);
            if (idx == -1) {
                Arrays.fill(last, -1);
                start = -1;
                formed = false;
            }
            else {
                start = start == -1 ? pos : start;
                last[idx] = pos;
                formed = true;
                for (int l : last) formed &= (l >= 0);
            }
            if (formed) {
                int min = pos;
                for (int l : last) min = Math.min(min, l);
                count += (min-start+1);
            }
        }
        return count;
    }
    
    private int index(char c) {
        if (c == 'a') return 0;
        if (c == 'e') return 1;
        if (c == 'i') return 2;
        if (c == 'o') return 3;
        if (c == 'u') return 4;
        return -1;
    }
}