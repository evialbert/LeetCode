class Solution {
  public int oddEvenJumps(int[] arr) {
        int n = arr.length;
        boolean[][] dp = new boolean[2][n+1];
        
        TreeMap<Integer, Integer> ascMap = new TreeMap<>(); 
        ascMap.put(arr[n-1], n-1);
        dp[1][n-1] = dp[0][n-1] = true;
        int ans = 0, next;
        Map.Entry<Integer, Integer> entry;
        
        for(int i=n-1; i>=0; i--){
            entry = ascMap.ceilingEntry(arr[i]);
            next = entry == null? n : entry.getValue();
            dp[1][i] |= dp[0][next];
            
            if(dp[1][i]) ans++;
            
            entry = ascMap.floorEntry(arr[i]);
            next = entry == null? n : entry.getValue();
            dp[0][i] |= dp[1][next];
            
            ascMap.put(arr[i], i);
        }
        return ans;
    }
}