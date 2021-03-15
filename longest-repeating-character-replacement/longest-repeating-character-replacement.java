class Solution {
    public int characterReplacement(String s, int k) {
        
        int i = 0 , j = 0;
        int N = s.length();
        int[]count = new int[128];
        int maxCharCount = 0;
        int max = 0;
        
        while(i < N)
        {   
            char ch = s.charAt(i);
            count[ch]++;
            
            maxCharCount = Math.max(maxCharCount , count[ch]);
            
            while(i - j - maxCharCount + 1  > k)
            {
                count[s.charAt(j)]--;
                j++;
            }
            
         max = Math.max(max,i - j + 1);   
         i++;
        }
      return max;  
    }
}