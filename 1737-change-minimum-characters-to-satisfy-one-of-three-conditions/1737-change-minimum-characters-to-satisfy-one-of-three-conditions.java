class Solution {
    public int minCharacters(String a, String b) {
        // strictly smaller or bigger means for each letter i, either all a smaller than i and b bigger than i, or b smaller than i and a bigger than i, if we record count for each letter in a, b we just need to add up the count bigger or smaller
        // for all a and b equal we just need to remove count of i
        
        int[] countsA = new int[26];
        int[] countsB = new int[26];
        
        for(int i = 0; i < a.length(); i++) countsA[a.charAt(i) - 'a']++;
        for(int i = 0; i < b.length(); i++) countsB[b.charAt(i) - 'a']++;
        
        int m = a.length();
        int n = b.length();
        int res = Integer.MAX_VALUE;
        int aSum = 0;
        int bSum = 0;
        
        for(int i = 0; i < 25; i++) {
            aSum += countsA[i];
            bSum += countsB[i];
            // make a >= i, b smaller than i
            int aBiggerOps = aSum + n - bSum;
            // make b >= i,
            int aSmallerOps = bSum + m - aSum;
            // all equal to i
            int equal = m + n - countsA[i] - countsB[i];
            
            res = Math.min(res, Math.min(aBiggerOps, Math.min(equal, aSmallerOps)));
            

        }
        
        return Math.min(res, m + n - countsA[25] - countsB[25]);
    }
}