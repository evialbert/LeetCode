class Solution {
    public int uniqueLetterString(String s) {
        
		int[] lastSeen = new int[26];
        Arrays.fill(lastSeen, -1);
        
        int[] secLastSeen = new int[26];
        Arrays.fill(secLastSeen, -1);
		
		int count = 0, res = 0;
	
		for (int i = 0; i < s.length(); i++) {
            int idx = s.charAt(i) - 'A';
            int p = lastSeen[idx];
            int q = secLastSeen[idx];
			
            count += i - p - p + q;
            res += count;
            
            secLastSeen[idx] = lastSeen[idx];
            lastSeen[idx] = i;
		}
        
		return res;
    }
}