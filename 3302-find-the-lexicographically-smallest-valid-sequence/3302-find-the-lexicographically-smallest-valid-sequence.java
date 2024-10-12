class Solution {
    public int[] validSequence(String word1, String word2) {
        int n = word1.length(), m = word2.length(), revGreedyMatchInd[] = new int[m];
        Arrays.fill(revGreedyMatchInd, -1);
        for(int i = n - 1, j = m - 1; j >= 0 && i >= 0; i--){
            if(word1.charAt(i) == word2.charAt(j))    revGreedyMatchInd[j--] = i;
        }
        boolean canSkip = true;
        int j = 0;
        for(int i = 0; i < n && j < m && m - j <= n - i; i++){
            if(word1.charAt(i) == word2.charAt(j)){
                revGreedyMatchInd[j++] = i;
            }else if(canSkip && (j == m - 1 || i < revGreedyMatchInd[j + 1])){
                revGreedyMatchInd[j++] = i;
                canSkip = false;
            }else if(!canSkip && revGreedyMatchInd[j] == -1)    break;
        }
        
        return j == m ? revGreedyMatchInd : new int[0];
    }
}