class Solution {
    public int minimumSwap(String s1, String s2) {
        int[] freqs = new int[2];
        int[] freqs1 = new int[2], freqs2 = new int[2];
        if (s1.length() != s2.length()){
            return -1;
        }
        char[] chars1 = s1.toCharArray(), chars2 = s2.toCharArray();
        
        for (int i = 0; i < chars1.length; i++){
            char c1 = chars1[i], c2 = chars2[i];
            freqs[c1 - 'x']++;
            freqs[c2 - 'x']++;
            if (c1 != c2){
                freqs1[c1 - 'x']++;
                freqs2[c2 - 'x']++;
            }
            
        }
       
        if (freqs[0] %2 == 1 || freqs[1] % 2 == 1){
            return -1;
        }
    
        int count = 0;
        int numXX1 = freqs1[0] / 2, numYY2 = freqs2[1] / 2;
        int pair1 = Math.max(numXX1, numYY2);
        count += pair1;
        int numXX2 = freqs2[0] / 2, numYY1 = freqs1[1] / 2;
        int pair2 = Math.max(numXX2, numYY1);
        count += pair2;
        
        if (freqs1[0] % 2 == 1){
            
            count += 2;
        }
        return count;
                 
    }
}