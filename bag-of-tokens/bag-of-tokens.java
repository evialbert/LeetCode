class Solution {
    // two pointers.
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens);
        int l = 0, r = tokens.length-1;
        int score = 0, maxScore = 0;
        
        while(l <= r){
            if(power >= tokens[l]){
                power -= tokens[l++];
                score++;
                maxScore = Math.max(score, maxScore);
            }else if(score > 0){
                power += tokens[r--];
                score--;
            }else{
                break;
            }
        }
        
        return maxScore;
    }
}