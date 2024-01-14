class Solution {
    public int maxFrequencyElements(int[] nums) {
        int[] freq = new int[101];
        int max = 0; //maximum freq
        
        for(int i : nums) {
            freq[i]++;
            if(freq[i]>max) max = freq[i];
        }
        
        int ans = 0;
        
        for(int i : nums) {
            if(freq[i] == max) { 
                ans++;
            }
        }
        
        return ans;
    }
}