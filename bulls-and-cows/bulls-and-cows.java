class Solution {
    public String getHint(String secret, String guess) {
        int bulls = 0, cows = 0;
        int len = secret.length();
        // create a buckets array to store the number of 0-9 in two strings
        int[] counts = new int[10];
        int[] countg = new int[10];
        
        // check bulls first!
        for(int i =0;i<len;i++){
            int n = secret.charAt(i) - '0';
            int m = guess.charAt(i) - '0';
            if(m == n) {
                bulls++;
            }else{
                counts[n]++;
                countg[m]++;
            }
        }
        // check cows!
        for(int j = 0; j<10;j++){
            cows += Math.min(counts[j],countg[j]);
        }
        
        return String.format("%dA%dB",bulls,cows);
    }
}
